#include <stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct Node{
	struct Node* lchild;
	int data;
	struct Node* rchild;
	Node(){
		lchild=rchild=NULL;
	}
}*root;

int search_in_Inorder(int x,int in[])
{//can use binary search
	int index;
	for(int i=0;i<10;i++)
	if(in[i]==x){
		index=i;
		break;
	}
	return index;
}

Node* create(int pre[], int in[], int low, int high)
{
	struct Node* p;
	static int i=0;
	int x;
	if(low>high)
	return NULL;
	//You may or may not write else statement as this underlying piece of code will only be executed
	//if(low<=high)
	x=pre[i++];
	p=new Node;
	p->data=x;
	int index=search_in_Inorder(x,in);
	p->lchild=create(pre,in,low,index-1);
	p->rchild=create(pre,in,index+1,high);
	return p;
}

void display(Node* root)
{
	if(root)
	{
		display(root->lchild);
		cout<<root->data<<" ";
		display(root->rchild);
	}
}

int main(){
	int *pre,*in;
	int length;
	cout<<"Enter the number of elements:";
	cin>>length;
	pre=new int[length];
	in=new int[length];
	cout<<"Enter the Preorder";
	for(int i=0;i<length;i++)
	cin>>pre[i];
	cout<<"Enter the inorder";
	for(int i=0;i<length;i++)
	cin>>in[i];
	root=new Node;
	root=create(pre,in,0,length-1);
	display(root);
	return 0;
}
//Time complexity: O(N^2)
//We can improve this using hashing which would bring down the searching part to O(1) at average so we would get
//time complexity of O(N).
