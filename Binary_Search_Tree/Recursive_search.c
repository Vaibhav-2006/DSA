#include<stdio.h>
#include<stdlib.h>
struct Node
{
struct Node *lchild;
int data;
struct Node *rchild;
}*root=NULL;
void RInsert(int key)
{
struct Node *t=root;
struct Node *r=NULL,*p;
if(root==NULL)
{
p=(struct Node *)malloc(sizeof(struct Node));
p->data=key;
p->lchild=p->rchild=NULL;
root=p;
return;
}
while(t!=NULL)
{
r=t;
if(key<t->data)
t=t->lchild;
else if(key>t->data)
t=t->rchild;
else
return;
}
p=(struct Node *)malloc(sizeof(struct Node));
p->data=key;
p->lchild=p->rchild=NULL;
if(key<r->data) r->lchild=p;
else r->rchild=p;
}
void Inorder(struct Node *p)
{
if(p)
{
Inorder(p->lchild);
printf("%d ",p->data);
Inorder(p->rchild);
}
}
struct Node * RSearch(struct Node* p,int key)
{
if(p==NULL) return NULL;
else if (p->data==key) return p;
else if(p->data<key) return RSearch(p->rchild,key);
else return RSearch(p->lchild,key);
}
int main()
{
struct Node *temp;
RInsert(50);
RInsert(10);
RInsert(40);
RInsert(20);
RInsert(30);
Inorder(root);
printf("\n");
temp=RSearch(root,20);
if(temp!=NULL)
printf("element %d is found\n",temp->data);
else
printf("element is not found\n");
return 0;
}
