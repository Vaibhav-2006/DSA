// C++(STL) program for Huffman Coding with STL
#include <bits/stdc++.h>
using namespace std;
 
// A Huffman tree node
struct Character
{
  char data; 
  unsigned int frequency;
  Character *left, *right;
  
  Character()
  {
  left=right=NULL;
  }
  
  Character(char data, unsigned int freq)
  {
 
        left = right = NULL;
        this->data = data;
        this->frequency = freq;
  }
  Character operator+(Character ch2)
  {
  	//temporary characters used for merging two characters do not need data to be intitialized.
    Character temp;
    temp.frequency=this->frequency+ch2.frequency;
    return temp;
  }
};
// For comparison of
// two heap nodes (needed in min heap)
struct compare {
 
    bool operator()(Character* l, Character* r)
 
    {
        return (l->frequency > r->frequency);
    }
};
 
// Prints huffman codes from
// the root of Huffman Tree.
void printCodes(struct Character* root, string str)
{
 
    if (!root)
        return;
 
    if (root->data != '$')
        cout << root->data << ": " << str << "\n";
 
    printCodes(root->left, str + "0");//string addition
    printCodes(root->right, str + "1");
}
 
// The main function that builds a Huffman Tree and
// print codes by traversing the built Huffman Tree
void HuffmanCodes(Character ch[], int size)
{
    struct Character *left, *right, *top;
 
    // Create a min heap & inserts all characters of data[]
    priority_queue<Character*, vector<Character*>, compare> minHeap;
 
    for (int i = 0; i < size; ++i)
        minHeap.push(&ch[i]);//Minheap is of Character pointers
 
    // Iterate while size of heap doesn't become 1
    while (minHeap.size() != 1) {
 
        // Extract the two minimum
        // freq items from min heap
        left = minHeap.top();
        minHeap.pop();
 
        right = minHeap.top();
        minHeap.pop();
 
        // Create a new internal node with
        // frequency equal to the sum of the
        // two nodes frequencies. Make the
        // two extracted node as left and right children
        // of this new node. Add this node
        // to the min heap '$' is a special value
        // for internal nodes, not used
        top = new Character('$', left->frequency + right->frequency);
 
        top->left = left;
        top->right = right;
 
        minHeap.push(top);
    }
 cout<<minHeap.top()->frequency<<endl;;
    // Print Huffman codes using
    // the Huffman tree built above
    printCodes(minHeap.top(), "");
}
 
// Driver Code
int main()
{
 
    Character ch[] = { {'a',5}, {'b',9}, {'c',12}, {'d',13}, {'e',16} , {'f',45} };
 
    int size = sizeof(ch) / sizeof(ch[0]);
 
    HuffmanCodes(ch, size);
 
    return 0;
}
