//Input  : geeksforgeeks
//Output : g
//(mind that it will be g, not e.)
//
//Input  : abcdabcd
//Output : a
//
//Input  : abcd
//Output : -1
//No character repeats
/*Simple Solution using O(N^2) complexity 
The solution is to loop through the string for each character and search for the same in the rest of the string. 
This would need two loops and thus not optimal.  */
// C++ program to find the first
// character that is repeated
#include <bits/stdc++.h>
#include <string.h>

using namespace std;
int findRepeatFirstN2(const string &s)
{
	// this is O(N^2) method
	for (int i = 0; i < s.length()-1; i++)//last character cannot be repeating
	{
		for (int j = i + 1; j < s.length(); j++)
		{
			if (s[i] == s[j])
			{
				return i;
			}
		}
	}

	return -1;
}

//Optimization by counting occurrences
//This solution is optimized by using the following techniques: 
//1. We loop through the string and hash the characters using ASCII codes. Store 1 if found and store 2 if found again. 
//2. We run a loop on the hash array and now we find the minimum position of any character repeated.
//This will have a runtime of O(N).
#define MAX_CHAR 256
#define NO_OF_CHARS 256
int findRepeatFirst(const string &s)
{
    // initialized counts of occurrences of
    // elements as zero
    int hash[MAX_CHAR] = { 0 };

    for (int i = 0; i < s.length() ; i++) 
	{
            hash[s[i]]++;
    }
 
    for (int i = 0; i < s.length(); i++) {
    	if(hash[s[i]]>1)
    		return i;
    }
 	return -1;
}

/*
Solving just by single traversal of the given string.

Algorithm :

1. Traverse the string from left to right.

2. If current character is not present in hash map, Then push this character along with its Index.

3. If the current character is already present in hash map, Then get the index of current character ( from hash map ) 
and compare it with the index of the previously found repeating character.

4. If the current index is smaller, then update the index.*/
int firstRep (const string &s)
    {
        unordered_map<char,int> map;
        int index=INT_MAX;
         
        // single traversal of string.
        for(int i=0;i<s.size();i++)
        {
            char p=s[i];
             
            if(map.find(p)==map.end())
			map[p]=i;//map.insert({p,i});
            else
            {
                if(map[p]<index)
                {
                    index=map[p];
                }
            }   
        }
         
         
        return index==INT_MAX?-1:index;
    }
    
/*
Time complexity:    O(N)
Space complexity:  O(N) on gfg but this is questionable as characters in string could be 256 distinct characters with 
many frequencies but still map stores only distinct characters. So maybe it should be O(1) only.
*/

/*
How to solve this problem using one traversal of input string? 
Another Method1 (Traversing from Left to Right) We traverse the string from left to right. We keep track of the leftmost 
index of every character. If a character repeats, we compare its leftmsot index with current result and 
update the result if result is greater */

int firstRepeating1(const string& str)
{
    // Initialize leftmost index of every
    // character as -1.
    int firstIndex[NO_OF_CHARS];
    fill(firstIndex, firstIndex+NO_OF_CHARS, -1);
 
    // Traverse from left and update result
    // if we see a repeating character whose
    // first index is smaller than current
    // result.
    int res = INT_MAX;
    for (int i = 0; i < str.length(); i++) {
    	int fi=firstIndex[str[i]];
        if (fi == -1)//element has not occurred yet.
           firstIndex[str[i]] = i;
        else//character has occurred before
           res = min(res, fi);
    }
 
    return (res == INT_MAX) ? -1 : res;
}
/*
Time Complexity : O(n). It does only one traversal of input string. 
Auxiliary Space : O(1)
Another similar method2 (Traversing Right to Left) We traverse the string from right to left. 
We keep track of the visited characters. If a character repeats, we update the result. */

int firstRepeating(const string& str)
{
    // Mark all characters as not visited
    bool visited[NO_OF_CHARS];
    for (int i = 0; i < NO_OF_CHARS; i++)
        visited[i] = false;
 
    // Traverse from right and update res as soon
    // as we see a visited character.
    int res = -1;
    for (int i = str.length() - 1; i >= 0; i--) {
        if (visited[str[i]] == false)//character has not repeated
            visited[str[i]] = true;
        else//character has repeated
            res = i;//we are not comparing with the previous value of res as we are traversing from right to left
    }//the last character which is repeated in this loop is infact the leftmost repeating character. 
 
    return res;
}
/*
Time Complexity : O(n). It does only one traversal of input string. 
Auxiliary Space : O(1)
The method 2 is better than method 1 as it does fewer comparisons.
*/
// Driver code
int main()
{
	string str = "geeksforgeeks";
	int pos = firstRepeating(str);
	if (pos == -1)
		cout << "Not found";
	else
		cout << str[pos];
	return 0;
}


