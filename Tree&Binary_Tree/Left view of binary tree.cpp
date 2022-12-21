#include <bits/stdc++.h>
using namespace std;
 
struct Node
{
    int data;
    struct Node *left, *right;
};

/*Method-1 (Using Recursion or preorder traversal)
The left view contains all nodes that are first nodes in their levels. 
A simple solution is to do level order traversal and print the first node in every level.

The problem can also be solved using simple recursive traversal. 
We can keep track of the level of a node by passing a parameter to all recursive calls. 
The idea is to keep track of the maximum level also. Whenever we see a node whose level is 
more than maximum level so far, we print the node because this is the first node in its level 
(Note that we traverse the left subtree before right subtree). */

struct Node *newNode(int item)
{
    struct Node *temp = (struct Node *)malloc(
                        sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
// Recursive function to print
// left view of a binary tree. Note that this is a helper function.
void leftViewUtil(struct Node *root, int level)
{
	static int max_level=0;
    // Base Case
    if (root == NULL) return;
 
    // If this is the first Node of its level
    if (max_level < level)
    {
        cout << root->data << " ";
        max_level = level;
    }
 
    // Recur for left subtree first,
    // then right subtree
    leftViewUtil(root->left, level + 1);
    leftViewUtil(root->right, level + 1);
}
 
// A wrapper over leftViewUtil()
void leftView(struct Node *root)
{
    leftViewUtil(root, 1);
}
/*
Time Complexity: The function does a simple traversal of the tree, so the complexity is O(n). 
Auxiliary Space: O(h), due to the stack space during recursive call. 
*/
/*
Method-2 (Using Queue):

In this method, level order traversal based solution is discussed. If we observe carefully, 
we will see that our main task is to print the left most node of every level. 
So, we will do a level order traversal on the tree and print the leftmost node at every level. 
Below is the implementation of above approach. It is similar to line by line level order traversal.*/

void printLeftView(Node* root)
{
    if (!root)
        return;
 	//Do not push root in queue if root is NULL
    queue<Node*> q;
    q.push(root);
 
    while (!q.empty())
    {    
        // number of nodes at current level
        int n = q.size();
         
        // Traverse all nodes of current level
        for(int i = 0; i < n; i++)
        {
            Node* temp = q.front();
            q.pop();
                 
            // Print the left most element
            // at the level
            if (i == 0)
                cout<<temp->data<<" ";
             
            // Add left node to queue
            if (temp->left != NULL)
                q.push(temp->left);
 
            // Add right node to queue
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}   
/*
Time Complexity: O(n), where n is the number of nodes in the binary tree.
Space complexity: O(width)
*/ 
 
// Driver Code
int main()
{
    Node* root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(8);
    root->right->right = newNode(15);
    root->right->left = newNode(12);
    root->right->right->left = newNode(14);
 
    printLeftView(root);
 
    return 0;
}
