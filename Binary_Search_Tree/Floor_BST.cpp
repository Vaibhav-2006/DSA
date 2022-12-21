//A simple solution is to traverse the tree using (Inorder or Preorder or Postorder) and keep 
//track of closest smaller or same element. Time complexity of this solution is O(n) where n is total number of Nodes in BST.
//We can efficiently find closest smaller or same element in O(h) time where h is height of BST. 
//Algorithm to find the floor of a key in a binary search tree (BST): 
/*
1 Start at the root Node.
2 If root->data == key, 
     floor of the key is equal 
     to the root.
3 Else if root->data > key, then 
     floor of the key must lie in the
     left subtree.
4 Else floor may lie in the right subtree 
  but only if there is a value lesser than 
  or equal to the key.If not, then root is
  the key.
*/
// C++ code to find floor of a key in BST
#include <bits/stdc++.h>
using namespace std;

/*Structure of each Node in the tree*/
struct Node {
	int data;
	Node *left, *right;
};

/*This function is used to create and
initializes new Nodes*/
Node* newNode(int key)
{
	Node* temp = new Node;
	temp->left = temp->right = NULL;
	temp->data = key;
	return temp;
}

/* This function is used to insert
new values in BST*/
Node* insert(Node* root, int key)
{
	if (!root)
		return newNode(key);
	if (key < root->data)
		root->left = insert(root->left, key);
	else
		root->right = insert(root->right, key);
	return root;
}

/*This function is used to find floor of a key*/
Node* floor(Node* root, int key)
{
	Node* res=NULL;
	while(root!=NULL)
	{
			/* If root->data is equal to key */
	if (root->data == key)
		return root;

	/* If root->data is greater than the key */
	if (root->data > key)
		root=root->left;

	/* Else, the floor may lie in right subtree
	or may be equal to the root*/
	else{
		res=root;
		root=root->right;
	}
	}
	return res;
}

int main()
{
	/* Let us create following BST
			7
			/ \
		5	 10
		/ \ / \
		3 6 8 12 */
	Node* root = NULL;
	root = insert(root, 7);
	insert(root, 10);
	insert(root, 5);
	insert(root, 3);
	insert(root, 6);
	insert(root, 8);
	insert(root, 12);
	cout << Recursivefloor(root, 9)->data << endl;
	return 0;
}

