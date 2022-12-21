//Bst can also be made from post order by pushing node pointers into the stack when moving right.
#include<iostream>
#include "C:\Users\vaibh\OneDrive\Desktop\Ds_Udemy_ABdul_Bari\Tree&Binary_Tree\Stack.h"
using namespace std;
#include<stdio.h>
struct Node{
	int data;
	struct Node *lchild,*rchild;
	Node(){
		lchild=rchild=NULL;
	}
	Node(int data){
	this->data=data;
	lchild=rchild=NULL;
	}
} *root,*dummy=new Node(INT_MAX);
// node pointed to by dummy stores infinity and sits at the bottom of the stack always.
// It is used so that stack is never empty and lowermost element of the stack is infinity.
void Create_pre(int pre[],int n)
{
	struct Node* t, *p;
	int i=0;
	Stack stk;
	Create_Stack(&stk,10);
	push(&stk,dummy);
	root=new Node;
	root->data=pre[i++];
	root->lchild=root->rchild=NULL;
	p=root;
	while(i<n)
	{
		if(pre[i]<p->data)
		{
			t=new Node(pre[i++]);
			p->lchild=t;
			push(&stk,p);
			p=t;
		}
		else {
			if(pre[i]>p->data&&pre[i]<top(&stk)->data)
			{
			t=new Node(pre[i++]);
			p->rchild=t;
			p=t;	
			}
			else
			p=pop(&stk);
		}
	}
}
void Inorder(struct Node *root)
{
	if(root)
	{
		Inorder(root->lchild);
		printf("%d ",root->data);
		Inorder(root->rchild);
	}
}
int main()
{
	int pre[10]={50,40,30,35,32,75,70,72};
	Create_pre(pre,8);
	Inorder(root);
}
