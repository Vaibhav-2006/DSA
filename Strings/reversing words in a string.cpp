//Example: Let the input string be “i like this program very much”. The function should change the string to 
//“much very program this like i”

/*
Algorithm:  

Initially, reverse the individual words of the given string one by one, for the above example, after reversing individual words the string should be “i ekil siht margorp yrev hcum”.
Reverse the whole string from start to end to get the desired output “much very program this like i” in the above example.
*/
// C++ program to reverse a string
#include <bits/stdc++.h>
using namespace std;

// Function to reverse words*/
void reversewords(string &s)
{
	
	// temporary vector to store all words
	vector<string> tmp;
	string str = "";
	for (int i = 0; i < s.length(); i++)
	{
		
		// Check if we encounter space
		// push word(str) to vector
		// and make str NULL
		if (s[i] == ' ')
		{
			tmp.push_back(str);
			str = "";
		}

		// Else add character to
		// str to form current word
		else
			str += s[i];
	}

	// Last word remaining,add it to vector
	tmp.push_back(str);

	// Now print from last to first in vector
	int i;
	for (i = tmp.size() - 1; i >= 0; i--)
		cout << tmp[i] << " ";
}

//Stack-based Approach:
/*
The idea here is to push all the words of str into the Stack and then print all the elements of the Stack. 
Follow the steps below to solve the problem:

Create a Stack to store each word of the string str.
Iterate over string str, and separate each word of str by a space delimiter.
Push all the words of str into the stack.
Print all the elements of the stack one by one.
*/

void printRev(string str)
{
    // Stack to store each
    // word of the string
    stack<string> st;
 
    // Store the whole string
    // in string stream
    stringstream ss(str);
 
    string temp;
    while (getline(ss, temp, ' ')) {//think what getline returns. ss is a stream which is read and then its contents are stored
 									//into temp until delimiter is found.
        // Push each word of the
        // string into the stack
        st.push(temp);
    }
 
    // Print the string in reverse
    // order of the words
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}
//Time: O(N) 
//Space : O(N)

//Now an interesting solution to solve the problem in O(1) space and O(N) time.
//using stl reverse we first reverse all the words and then reverse the entire string.
//hello vaibhav
//olleh vahbiav
//vaibhav hello
void reverseWords(string str)
{
	int start=0;//start of a word.
	for(int end=0; end<str.length(); end++)
	{//end of a word
		if(str[end]==' ')
		{
			reverse(str.begin()+start,str.begin()+end);//reversing individual words.. see that str[end] is currently ' ' but 
			start=end+1;//still we are passing it as stl::iterator to reverse as some memory lying immediately outside the valid 
		}//string is passed 
	}
	reverse(str.begin()+start,str.begin()+str.length());//revsersing the last word as there might be no space after last word.
	reverse(str.begin(),str.begin()+str.length());
	cout<<str;
}
// Driver Code
int main()
{
	string s = "i like this program very much";
	reverseWords(s);
	return 0;
}

