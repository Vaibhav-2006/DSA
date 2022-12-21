// C++ implementation to print the character and
// its frequency in order of its occurrence
#include <bits/stdc++.h>
using namespace std;


// function to print the character and its frequency
// in order of its occurrence
void printCharWithFreq_inorder(string str)
{
	// size of the string 'str'
	int n = str.size();

	// 'freq[]' implemented as count array
	int freq[26]={0};//It is constant space O(1)
	//Above assignemnt sets all values in freq[] = 0. We can also use memset or a vector which has elements
	//with default value 0.
	
	// accumulate frequency of each character in 'str'
	for (int i = 0; i < n; i++)
		freq[str[i] - 'a']++;

	// traverse 'str' from left to right
	for (int i = 0; i < n; i++) {

		// if frequency of character str[i] is not
		// equal to 0
		if (freq[str[i] - 'a'] > 0) {

			// print the character along with its
			// frequency
			cout << str[i] << " "<<freq[str[i] - 'a'] << "   ";

			// update frequency of str[i] to 0 so
			// that the same character is not printed
			// again
			freq[str[i] - 'a'] = 0;
		}
	}
}

void prCharWithFreq_inorder(string s)
{
  // Store all characters and
  // their frequencies in dictionary
  unordered_map<char, int> d;
 
  for(char i : s)
  {
    d[i]++;
  }
 
  // Print characters and their
  // frequencies in same order
  // of their appearance
  for(char i : s)
  {
    // Print only if this
    // character is not printed
    // before
    if(d[i] != 0)
    {
      cout << i << d[i] << " ";
      d[i] = 0;
    }
  }
}
Above implementation is also O(1) space despite the hash table.
void printCharWithFreq_Sortedorder(string str)
{
	// size of the string 'str'
	int n = str.size();

	int freq[26]={0};//It is constant space O(1)
	//Above assignemnt sets all values in freq[] = 0. We can also use memset or a vector which has elements
	//with default value 0.
	
	// accumulate frequency of each character in 'str'
	for (int i = 0; i < n; i++)
		freq[str[i] - 'a']++;

	// traverse freq from left to right
	for (int i = 0; i < 26; i++) {//This is O(1) time 

		// if frequency of character str[i] is not
		// equal to 0
		if (freq[i] > 0) {

			// print the character along with its
			// frequency
			cout << (char) (i+'a') << " "<<freq[i] << "   ";
		}
	}
}

void print_Sorted_String(string str)
{
	// size of the string 'str'
	int n = str.size();

	int freq[26]={0};//It is constant space O(1)
	//Above assignemnt sets all values in freq[] = 0. We can also use memset or a vector which has elements
	//with default value 0.
	
	// accumulate frequency of each character in 'str'
	for (int i = 0; i < n; i++)
		freq[str[i] - 'a']++;
	
	for(int i=0;i<26;i++)
	{
		if(freq[i]>0)
		{
			while(freq[i]>0)
			{
				cout<<char(i+'a');
				freq[i]--;
			}
		}
	}	
}
//Time complexity: Above program takes O(N) time and not O(N^2) as outer for loop will run
//for 26 times(constant) but we will only enter the if condition for every distinct element in 
//string. And since we are merely printing a string of size N, time is O(N).
//Space complexity: O(1).
// Driver program to test above
int main()
{
	string str = "geeksforgeeks";
	print_Sorted_String(str);
	return 0;
}

