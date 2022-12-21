/*
In general for a string of length n there are 2^n subsequences possible. 
Given two strings str1 and str2, find if str1 is a subsequence of str2. A subsequence is a 
sequence that can be derived from another sequence by deleting some elements without changing 
the order of the remaining elements.
Input: str1 = "AXY", str2 = "ADXCPY"
Output: True (str1 is a subsequence of str2)

Input: str1 = "AXY", str2 = "YADXCP"
Output: False (str1 is not a subsequence of str2)

Input: str1 = "gksrek", str2 = "geeksforgeeks"
Output: True (str1 is a subsequence of str2)
*/
// Iterative C++ program to check
// if a string is subsequence
// of another string
#include <cstring>
#include <iostream>
using namespace std;

// Returns true if str1[] is a
// subsequence of str2[]. m is
// length of str1 and n is length of str2
bool isSubSequence(const string &str1, const string &str2, int m, int n)
{//pass strings as reference to avoid copying of characters into a new string. This also speeds up your program. Now
//since we are using reference we can change the original string accidentally so we have used const. Also m and n may not 
// be passed as we can get size as str1.length()
	int j = 0; // For index of str1 (or subsequence)
	if(m>n) return false; //str1.length() cannot be greater than str2.length()
	// Traverse str2 and str1, and
	// compare current character
	// of str2 with first unmatched char
	// of str1, if matched
	// then move ahead in str1
	for (int i = 0; i < n && j < m; i++)
		if (str2[i] == str1[j])
			j++;//if character in str1 and str2 is same then i++ and j++ else only i++.

	// If all characters of str1 were found in str2
	return (j == m);
}

//Recursive solution
//The idea is simple, we traverse both strings from one side to other side (say from rightmost character to leftmost).
//If we find a matching character, we move ahead in both strings. Otherwise we move ahead only in str2. 

//Following is Recursive Implementation of the above idea.  

bool isSubSequence(char str1[], char str2[], int m, int n)
{
     
    // Base Cases
    if (m == 0)
        return true;
    if (n == 0)
        return false;
 
    // If last characters of two
    // strings are matching
    if (str1[m - 1] == str2[n - 1])
        return isSubSequence(str1, str2, m - 1, n - 1);
 
    // If last characters are
    // not matching
    return isSubSequence(str1, str2, m, n - 1);
}
//Time Complexity of both implementations above is O(n) where n is the length of str2. 
//Aux space is used for recursive solution: O(m+n)
// Driver program
int main()
{
	char str1[] = "gksrek";
	char str2[] = "geeksforgeeks";
	int m = strlen(str1);
	int n = strlen(str2);
	isSubSequence(str1, str2, m, n) ? cout << "Yes "
									: cout << "No";
	return 0;
}

