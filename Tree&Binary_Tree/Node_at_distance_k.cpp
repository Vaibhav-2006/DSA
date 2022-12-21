#include<bits/stdc++.h>

using namespace std;

class node
{
	public:
	int data;
	node* left;
	node* right;
	
	node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

void printKDistant(node *root , int k)
{
	if(root == NULL|| k < 0 )//k<0 is checked so that invalid distance is never passed 
		return;//to this function
	if( k == 0 )
	{
		cout << root->data << " ";
		return;
	}
	else
	{
		printKDistant( root->left, k - 1 ) ;
		printKDistant( root->right, k - 1 ) ;
	}
}

int main()
{

	/* Constructed binary tree is
		  1
		/   \
	   2	 3
		/ \	 /
		4 5 8
	*/
	node *root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(8);
	
	printKDistant(root, 2);
	return 0;
}

/*
Time Complexity: O(n) where n is number of nodes in the given binary tree.

 Space Complexity : O(height of the binary tree).
 */

