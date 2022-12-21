/* Program to check children sum property */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, left
child and right child */
struct node
{
	int data;
	struct node* left;
	struct node* right;
	node(int data)
	{
		this->data=data;
		left=right=NULL;
	}
};

/* returns 1 if children sum property holds
for the given node and both of its children*/
int isSumProperty(struct node* node)
{
	/* left_data is left child data and
	right_data is for right child data*/
	int left_data = 0, right_data = 0;
	
	/* If node is NULL or it's a leaf node
	then return true */
	if(node == NULL ||
		(node->left == NULL &&
		node->right == NULL))
		return 1;
	else
	{
		/* If left child is not present then 0
		is used as data of left child */
		if(node->left != NULL)
		left_data = node->left->data;
	
		/* If right child is not present then 0
		is used as data of right child */
		if(node->right != NULL)
		right_data = node->right->data;
	
		/* if the node and both of its children
		satisfy the property return 1 else 0*/
		if((node->data == left_data + right_data)&&
			isSumProperty(node->left) &&
			isSumProperty(node->right))
		return 1;
		else
		return 0;
	}
}


// Driver Code
int main()
{
	struct node *root = new node(10);
	root->left	 = new node(8);
	root->right = new node(2);
	root->left->left = new node(3);
	root->left->right = new node(5);
	root->right->right = new node(2);
	if(isSumProperty(root))
		cout << "The given tree satisfies "
			<< "the children sum property ";
	else
		cout << "The given tree does not satisfy "
			<< "the children sum property ";

	return 0;
}
/*
Time Complexity: O(n), we are doing a complete traversal of the tree.
Space complexity: O(h)
*/

