//Line by line level order traversal
//Firstly let us look at another way for iterative level order traversal
//This is using height of tree and print nodes at distance k from root.
/*
/* 
void printLevelOrder(struct node* root)
{
	int h = height(root);
	int i;
	for (i=1; i<=h; i++)
	{
		printGivenLevel(root, i);
		printf("\n");
	}
}


void printGivenLevel(struct node* root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		printf("%d ", root->data);
	else if (level > 1)
	{
		printGivenLevel(root->left, level-1);
		printGivenLevel(root->right, level-1);
	}
}
*/

//The time complexity of the above solution is O(n^2)

//Using the queue method time complexity is reduced to O(n) but space complexity is increased to O(n)

#include <iostream>
#include <queue>
using namespace std;
 

struct node
{
    struct node *left;
    int data;
    struct node *right;
};
 
// Iterative method to do level order traversal
// line by line
void printLevelOrder1(node *root)
{
    if (root == NULL) return;
 
    // Create an empty queue for level order traversal
    queue<node *> q;
 
    // Enqueue Root and NULL, NULL here signifies the end of a level
    q.push(root);
 	q.push(NULL);
    while (q.size()>1)//because at last a NULL will remain in the queue signifying the end of the 
    {//last level. we may or may not print  it.
		node *curr=q.front();
		q.pop();
		if(curr==NULL)
		{
			cout<<endl;
			q.push(NULL);//because we have encountered a NULL it means that the current level is
			continue;//finished and the next level has already been enqueued and thus another NULL is pushed
		}//which will signify the end of the next level.
        	cout<<curr->data<<" ";//continue statement above is very important
            //as NULL->data does not exist.
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
    }
}
//Time complexity of this method is O(n) where n is number of nodes in given binary tree.
//Aux space is O(width+1). That +1 is for NULL at last level but this +1 may be ignored because it is
//constant space.

void printLevelOrder(node *root)
{
    if (root == NULL) return;
 
    // Create an empty queue for level order traversal
    queue<node *> q;
 
    // Enqueue Root
    q.push(root);
 
    while (!q.empty())
    {
        // nodeCount (queue size) indicates number
        // of nodes at current level.
        int nodeCount = q.size();
 
        // Dequeue all nodes of current level and
        // Enqueue all nodes of next level
        for(int i=0; i<nodeCount; i++)// do not use i<q.size() as q.size will keep on changing
        {//in the loop and we will get wrong output. 
            node *curr = q.front();
            cout << curr->data << " ";
            q.pop();
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
        cout << endl;// new line is printed after an entire level is processed.
    }
}
 
// Utility function to create a new tree node
node* newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
 
// Driver program to test above functions
int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
 
    printLevelOrder(root);
    return 0;
}


