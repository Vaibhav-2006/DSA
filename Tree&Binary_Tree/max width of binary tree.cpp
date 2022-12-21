// A queue based C++ program to find maximum width
// of a Binary Tree
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

/*
In this method, we store all the child nodes at the current level in the queue and then count the total number 
of nodes after the level order traversal for a particular level is completed. Since the queue now contains all 
the nodes of the next level, we can easily find out the total number of nodes in the next level by finding the 
size of queue. We then follow the same procedure for the successive levels. We store and update the maximum number 
of nodes found at each level. This is similar to level order traversal done line by line. 
*/
// Function to find the maximum width of the tree
// using level order traversal
int maxWidth(struct Node* root)
{
	// Base case
	if (root == NULL)
		return 0;

	// Initialize result
	int result = 0;

	// Do Level order traversal keeping track of number
	// of nodes at every level.
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		// Get the size of queue when the level order
		// traversal for one level finishes
		int count = q.size();

		// Update the maximum node count value
		result = max(count, result);

		// Iterate for all the nodes in the queue currently
		while (count--) {
			// Dequeue an node from queue
			Node* temp = q.front();
			q.pop();

			// Enqueue left and right children of
			// dequeued node
			if (temp->left != NULL)
				q.push(temp->left);
			if (temp->right != NULL)
				q.push(temp->right);
		}
	}

	return result;
}

struct Node* newNode(int data)
{
	struct Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

int main()
{
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->right = newNode(8);
	root->right->right->left = newNode(6);
	root->right->right->right = newNode(7);

	/* Constructed Binary tree is:
				1
			/ \
			2	 3
		/ \	 \
		4 5	 8
					/ \
				6	 7 */
	
	// Function call
	cout << "Maximum width is " << maxWidth(root) << endl;
	return 0;
}

/*
Time Complexity: O(N) where N is the total number of nodes in the tree. In level order traversal, 
every node of the tree is processed once and hence the complexity due to the level order traversal is O(N) if 
there are total N nodes in the tree. Therefore, the time complexity is O(N).

Auxiliary Space: O(w) where w is the maximum width of the tree.
In level order traversal, a queue is maintained whose maximum size at any moment can go upto the 
maximum width of the binary tree.
*/
