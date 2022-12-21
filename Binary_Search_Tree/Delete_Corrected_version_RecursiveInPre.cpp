//Corrected version of Delete 
//Using recursive version of InPre and InSucc
#include<stdio.h>
#include<stdlib.h>
struct Node
{
struct Node *lchild;
int data;
struct Node *rchild;
}*root=NULL;


void Pre(struct Node* p)
{
	if(p)
	{
		printf("%d ",p->data);
		Pre(p->lchild);
		Pre(p->rchild);
	}
}

int Height(struct Node* p)
{
	if(p==NULL)
	return 0;
	int x=Height(p->lchild);
	int y=Height(p->rchild);
	return x>y?x+1:y+1;
}

struct Node *RInsert(struct Node *p,int key)
{
if(p==NULL)
{
p=(struct Node *)malloc(sizeof(struct Node));
p->data=key;
p->lchild=p->rchild=NULL;
return p;
}
if(key < p->data)
p->lchild=RInsert(p->lchild,key);
else if(key > p->data)
p->rchild=RInsert(p->rchild,key);
return p;
}


struct Node* InPre(struct Node* p){
	if(p->rchild)
	return InPre(p->rchild);
	return p;
}

struct Node* InSucc(struct Node* p)
{
	if(p->lchild)
	return InSucc(p->lchild);
	return p;
}


struct Node *Delete(struct Node *p,int key)
{
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
}
else
{
	printf("\nGiven key=%d does not exist",key);
	return p;
}
}
if(key < p->data)
p->lchild=Delete(p->lchild,key);
else if(key > p->data)
p->rchild=Delete(p->rchild,key);
else
{
if(Height(p->lchild)>Height(p->rchild))
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
return p;
}


int main()
{
struct Node *temp;
root=RInsert(root,50);
RInsert(root,10);
RInsert(root,40);
RInsert(root,20);
RInsert(root,30);
printf("\n");
Pre(root);
Delete(root,20);
printf("\n");
Pre(root);
return 0;}
