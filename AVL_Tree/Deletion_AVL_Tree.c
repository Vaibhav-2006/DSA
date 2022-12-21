#include <stdio.h>
#include<stdlib.h>
#include "C:\Users\vaibh\OneDrive\Desktop\Ds_Udemy_ABdul_Bari\AVL_Tree\Queue.h"
//Queue is only used for level order traversal
struct Node
{
struct Node *lchild;
int data;
int height;
struct Node *rchild;
}*root=NULL;


int NodeHeight(struct Node *p)
{
int hl,hr;
hl=p && p->lchild?p->lchild->height:0;
hr=p && p->rchild?p->rchild->height:0;
return hl>hr?hl+1:hr+1;
}


int BalanceFactor(struct Node *p)
{
int hl,hr;
hl=p && p->lchild?p->lchild->height:0;
hr=p && p->rchild?p->rchild->height:0;
return hl-hr;
}


struct Node * LLRotation(struct Node *p)
{
struct Node *pl=p->lchild;
struct Node *plr=pl->rchild;
pl->rchild=p;
p->lchild=plr;
p->height=NodeHeight(p);
pl->height=NodeHeight(pl);
if(root==p)
root=pl;
return pl;
}


struct Node * LRRotation(struct Node *p)
{
struct Node *pl=p->lchild;
struct Node *plr=pl->rchild;
pl->rchild=plr->lchild;
p->lchild=plr->rchild;
plr->lchild=pl;
plr->rchild=p;
pl->height=NodeHeight(pl);
p->height=NodeHeight(p);
plr->height=NodeHeight(plr);
if(root==p)
root=plr;
return plr;
}


struct Node * RRRotation(struct Node *p)
{
struct Node* pr=p->rchild;
struct Node* prl=pr->lchild;
pr->lchild=p;
p->rchild=prl;
p->height=NodeHeight(p);
pr->height=NodeHeight(pr);
if(p==root)
root=pr;
return pr;
}


struct Node * RLRotation(struct Node *p)
{
struct Node* pr=p->rchild;
struct Node* prl=pr->lchild;
p->rchild=prl->lchild;
pr->lchild=prl->rchild;
prl->lchild=p;
prl->rchild=pr;
p->height=NodeHeight(p);
pr->height=NodeHeight(pr);
prl->height=NodeHeight(prl);
if(root==p)
root=prl;
return prl;
}


struct Node *RInsert(struct Node *p,int key)
{
	int x,y,z;
struct Node *t=NULL;
if(p==NULL)
{
t=(struct Node *)malloc(sizeof(struct Node));
t->data=key;
t->height=1;
t->lchild=t->rchild=NULL;
return t;
}
if(key < p->data)
p->lchild=RInsert(p->lchild,key);
else if(key > p->data)
p->rchild=RInsert(p->rchild,key);
p->height=NodeHeight(p);
x=BalanceFactor(p);
y=BalanceFactor(p->lchild);
z=BalanceFactor(p->rchild);
if(x==2 && y==1)
return LLRotation(p);
else if(x==2 && y==-1)
return LRRotation(p);
else if(x==-2 && z==-1)
return RRRotation(p);
else if(x==-2 && z==1)
return RLRotation(p);
return p;
}

void Inorder(struct Node* p)
{
	if(p)
	{
		Inorder(p->lchild);
		printf("%d ",p->data);
		Inorder(p->rchild);
	}
}

void LevelOrder(struct Node *root)
{
Queue q;
create(&q,100);
printf("%d ",root->data);
enqueue(&q,root);
while(!isEmpty(q))
{
root=dequeue(&q);
if(root->lchild)
{
printf("%d ",root->lchild->data);
enqueue(&q,root->lchild);
}
if(root->rchild)
{
printf("%d ",root->rchild->data);
enqueue(&q,root->rchild);
}
}
}


struct Node *InPre(struct Node *p)
{
while(p && p->rchild!=NULL)
p=p->rchild;
return p;
}

struct Node *InSucc(struct Node *p)
{
while(p && p->lchild!=NULL)
p=p->lchild;
return p;
}


struct Node *Delete(struct Node *p,int key)
{
	int x,y,z;
struct Node *q;
if(p==NULL)
return NULL;
if(p->lchild==NULL && p->rchild==NULL)
{
if(key==p->data)
{
if(p==root)
root=NULL;
free(p);
return NULL;
//The actual deleted node is a leaf node always.
}
else 
{
return p;
}
}
if(key < p->data)
p->lchild=Delete(p->lchild,key);
else if(key > p->data)
p->rchild=Delete(p->rchild,key);
else
{
if(NodeHeight(p->lchild)>NodeHeight(p->rchild))
{
q=InPre(p->lchild);
p->data=q->data;
p->lchild=Delete(p->lchild,q->data);
}
else
{
q=InSucc(p->rchild);
p->data=q->data;
p->rchild=Delete(p->rchild,q->data);
}
}
//Since node is deleted height has to be balanced again for all the nodes
//lying above the deleted node.
p->height=NodeHeight(p);
x=BalanceFactor(p);
y=BalanceFactor(p->lchild);
z=BalanceFactor(p->rchild);
if(x==2 && y==1)//Check***
return LLRotation(p);
else if(x==2 && (y==-1||y==0))//Check*
return LRRotation(p);
else if(x==-2 && z==-1)
return RRRotation(p);
else if(x==-2 && (z==-1||z==0))//Check**
return RLRotation(p);
return p;
}


int main()
{
root=RInsert(root,10);
RInsert(root,20);
RInsert(root,30);
RInsert(root,40);
RInsert(root,50);
RInsert(root,60);
Inorder(root);
printf("\n");
LevelOrder(root);
Delete(root,50);
printf("\n");
Inorder(root);
printf("\n");
LevelOrder(root);
Delete(root,60);
printf("\n");
Inorder(root);
printf("\n");
LevelOrder(root);
return 0;
}

// *For tree
//      20
//   10    30
// 5  11
//If 30 is deleted balance factor of 20 is 2 and that of 10 is 0 so we can perform
//either LL or LR rotation
//**Same case as above but deletion is done on left subtree so p becomes heavy on the right side.
// x,y,z are used instead of expression like if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1);
//***so that number of function calls are reduced.
