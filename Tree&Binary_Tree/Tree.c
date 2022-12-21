//This is a C way of coding Tree.
#include<iostream>
#include <stdio.h>
#include "C:\Users\vaibh\OneDrive\Desktop\Ds_Udemy_ABdul_Bari\Tree&Binary_Tree\Queue.h"
#include "C:\Users\vaibh\OneDrive\Desktop\Ds_Udemy_ABdul_Bari\Tree&Binary_Tree\Stack.h"
using namespace std;


struct Node *root=NULL;


void Treecreate()
{
struct Node *p,*t;
int x;
struct Queue q;
create(&q,100);
printf("Enter root value ");
scanf("%d",&x);
root=(struct Node *)malloc(sizeof(struct Node));
root->data=x;
root->lchild=root->rchild=NULL;
enqueue(&q,root);
while(!isEmpty(q))
{
p=dequeue(&q);
printf("enter left child of %d ",p->data);
scanf("%d",&x);
if(x!=-1)
{
t=(struct Node *)malloc(sizeof(struct
Node));
t->data=x;
t->lchild=t->rchild=NULL;
p->lchild=t;
enqueue(&q,t);
}
printf("enter right child of %d ",p->data);
scanf("%d",&x);
if(x!=-1)
{
t=(struct Node *)malloc(sizeof(struct
Node));
t->data=x;
t->lchild=t->rchild=NULL;
p->rchild=t;
enqueue(&q,t);
}
}
}


void Preorder(struct Node *p)
{
if(p)
{
printf("%d ",p->data);
Preorder(p->lchild);
Preorder(p->rchild);
}
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

void Postorder(struct Node *p)
{
if(p)
{
Postorder(p->lchild);
Postorder(p->rchild);
printf("%d ",p->data);
}
}

void Levelorder(struct Node *root)
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

void IPreorder(struct Node *p)
{
struct Stack stk;
Create_Stack(&stk,100);
while(p || !isEmpty_Stack(stk))
{
if(p)
{
printf("%d ",p->data);
push(&stk,p);
p=p->lchild;
}
else
{
p=pop(&stk);
p=p->rchild;
}
}
}


void IInorder(struct Node *p)
{
struct Stack stk;
Create_Stack(&stk,100);
while(p || !isEmpty_Stack(stk))
{
if(p)
{
push(&stk,p);
p=p->lchild;
}
else
{
p=pop(&stk);
printf("%d ",p->data);
p=p->rchild;
}
}
}

void IPostorder(struct Node *root){
	Stack stk;
	Create_Stack(&stk,100);
while(true) {
            while(root !=NULL) {
                push(&stk,root);
                push(&stk,root);
                root = root->lchild;
            }
             
            // Check for empty stack
            if(isEmpty_Stack(stk)) return;
            root = pop(&stk);
             
            if(!isEmpty_Stack(stk) && top(&stk) == root) 
			root = root->rchild;
             
            else {
                 
                printf("%d ",root->data) ;
				root = NULL;
            }
        }
    }

int Height(struct Node *root)
{
int x=0,y=0;
if(root==0)
return 0;
x=Height(root->lchild);
y=Height(root->rchild);
if(x>y)
return x+1;
else
return y+1;
}

int main()
{
	Node* t;
	Stack stck;
	Create_Stack(&stck,10);
	Treecreate();
	printf("\nPre Order ");
	Preorder(root);
	printf("\nIn Order ");
	Inorder(root);
	printf("\nPost Order ");
	Postorder(root);
	printf("\nLevel Order ");
	Levelorder(root);
	printf("\nHeight= %d",Height(root)-1);
	printf("\nIterative PreOrder ");
	IPreorder(root);
	printf("\nIterative InOrder ");
	IInorder(root);	
	printf("\nIterative PostOrder ");
	IPostorder(root);	
	return 0;
}
//O(n) approach for iterative post order
//void postOrderIterative(Node* root)
//{
//    if (root == NULL)
//        return;
// 
//    // Create two stacks
//    stack<Node *> s1, s2;
// 
//    // push root to first stack
//    s1.push(root);
//    Node* node;
// 
//    // Run while first stack is not empty
//    while (!s1.empty()) {
//        // Pop an item from s1 and push it to s2
//        node = s1.top();
//        s1.pop();
//        s2.push(node);
// 
//        // Push left and right children
//        // of removed item to s1
//        if (node->left)
//            s1.push(node->left);
//        if (node->right)
//            s1.push(node->right);
//    }
// 
//    // Print all elements of second stack
//    while (!s2.empty()) {
//        node = s2.top();
//        s2.pop();
//        cout << node->data << " ";
//    }
//}
