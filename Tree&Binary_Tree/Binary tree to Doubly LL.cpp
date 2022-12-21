//Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. 
//The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL. 
//The order of nodes in DLL must be the same as in Inorder for the given Binary Tree. 
//The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.

/*he idea is to do in order traversal of the binary tree. While doing inorder traversal, keep track of 
the previously visited node in a variable, say prev. For every visited node, make it next to the prev and 
previous of this node as prev.*/ 

// A C++ program for in-place conversion of Binary Tree to DLL
#include <iostream>
using namespace std;

/* A binary tree node has data, and left and right pointers */
struct node
{
	int data;
	node* left;
	node* right;
};

// A simple recursive function to convert a given Binary tree to Doubly
// Linked List
// root --> Root of Binary Tree
// head --> Pointer to head node of created doubly linked list
void BinaryTree2DoubleLinkedList(node *root, node* &head)
{//Why node* &head? Note that if we had used node* head then the head in main would remain null and head in this 
//function would point to the correct head of linked list but tould not be passed to head in main. So we have made head
//in this function an alias of the head in main such that these both pointers have the same address.
//Note that we can even use a double pointer. 
	
	if (root == NULL) return;

	// Initialize previously visited node as NULL. This is
	// static so that the same value is accessible in all recursive
	// calls
	static node* prev = NULL;

	// Recursively convert left subtree
	BinaryTree2DoubleLinkedList(root->left, head);

	// Now convert this node
	if (prev == NULL)
		head = root;
	else
	{
		root->left = prev;
		prev->right = root;
	}
	prev = root;

	// Finally convert right subtree
	BinaryTree2DoubleLinkedList(root->right, head);
}

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
node* newNode(int data)
{
	node* new_node = new node;
	new_node->data = data;
	new_node->left = new_node->right = NULL;
	return (new_node);
}

/* Function to print nodes in a given doubly linked list */
void printList(node *node)
{
	while (node!=NULL)
	{
		cout << node->data << " ";
		node = node->right;
	}
}

/* Driver program to test above functions*/
int main()
{
	// Let us create the tree shown in above diagram
	node *root	 = newNode(10);
	root->left	 = newNode(12);
	root->right	 = newNode(15);
	root->left->left = newNode(25);
	root->left->right = newNode(30);
	root->right->left = newNode(36);

	// Convert to DLL
	node *head = NULL;
	BinaryTree2DoubleLinkedList(root, head);

	// Print the converted list
	printList(head);

	return 0;
}
//Note that the use of static variables like above is not a recommended practice (we have used static for simplicity). 
//Imagine a situation where the same function is called for two or more trees. The old value of prev would be used in 
//the next call for a different tree. To avoid such problems, we can use a double-pointer or reference to a pointer.
//Time Complexity: The above program does a simple inorder traversal, so time complexity is O(n)
//where n is the number of nodes in given binary tree.
