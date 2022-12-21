// C++ program to find maximum and
// minimum in a Binary Tree
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// A tree node
class Node {
public:
	int data;
	Node *left, *right;

	Node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

// Returns maximum value in a given
// Binary Tree
int findMax(Node* root)
{
	// Base case
	if (root == NULL)
		return INT_MIN;

	// Return maximum of 3 values:
	// 1) Root's data 2) Max in Left Subtree
	// 3) Max in right subtree
	return max(root->data, max( findMax(root->left), findMax(root->right)));
}

// Driver Code
int main()
{
	Node* NewRoot = NULL;
	Node* root = new Node(2);
	root->left = new Node(7);
	root->right = new Node(5);
	root->left->right = new Node(6);
	root->left->right->left = new Node(1);
	root->left->right->right = new Node(11);
	root->right->right = new Node(9);
	root->right->right->left = new Node(4);

	cout << "Maximum element is " << findMax(root) << endl;

	return 0;
}
/*
Complexity Analysis:

Time Complexity: O(N).
In the recursive function calls, every node of the tree is processed once and hence the complexity 
due to the function is O(N) if there are total N nodes in the tree. Therefore, the time complexity
is O(N).

Space Complexity: O(h).
At max the number of calls in the function call stack will be h+1 where h is 1 based(nodes are counted).

We can also use level order traversal for this and that will give space complexity O(width) and will
give good results for a skewed tree. 
*/
