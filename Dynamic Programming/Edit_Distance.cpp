/*If last characters of two strings are same, nothing much to do. 
Ignore last characters and get count for remaining strings. 
So we recur for lengths m-1 and n-1.
Else (If last characters are not same), we consider all operations on ‘str1’, 
consider all three operations on last character of first string, 
recursively compute minimum cost for all three operations and take minimum of three values. 
Insert: Recur for m and n-1
Remove: Recur for m-1 and n
Replace: Recur for m-1 and n-1
Below is implementation of above Naive recursive solution.*/

// A Naive recursive C++ program to find minimum number
// operations to convert str1 to str2
#include <bits/stdc++.h>
using namespace std;

// Utility function to find minimum of three numbers
int min(int x, int y, int z) { return std::min(std::min(x, y), z); }

int editDist(string str1, string str2, int m, int n)
{
	// If first string is empty, the only option is to
	// insert all characters of second string into first
	if (m == 0)
		return n;

	// If second string is empty, the only option is to
	// remove all characters of first string
	if (n == 0)
		return m;

	// If last characters of two strings are same, nothing
	// much to do. Ignore last characters and get count for
	// remaining strings.
	if (str1[m - 1] == str2[n - 1])
		return editDist(str1, str2, m - 1, n - 1);

	// If last characters are not same, consider all three
	// operations on last character of first string,
	// recursively compute minimum cost for all three
	// operations and take minimum of three values.
	return 1 + min(editDist(str1, str2, m, n - 1), // Insert
				editDist(str1, str2, m - 1, n), // Remove
				editDist(str1, str2, m - 1, n - 1));// Replace
}

//Tabulation based solution 
int editDistDP(string str1, string str2, int m, int n)
{
    // Create a table to store results of subproblems
    int dp[m + 1][n + 1];
 
 
	for (int i = 0; i <= m; i++)
	{
		dp[i][0]=i;//when 2nd string is empty, deletions have to be done in 1st string.
	}
	
	for (int j = 1; j <= n; j++)
	{
		dp[j][0]=j;//when 1st string is empty we have to do insertions in 1st string.
	}
	
	
    // Fill d[][] in bottom up manner
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            
            // If last characters are same, edit distance remains same as it was for
            //s1[0...i-2] and s2[0...j-2]
        	if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
 
            // If the last character is different, consider
            // all possibilities and find the minimum
            else
                dp[i][j] = 1 + min(dp[i][j - 1], // Insert
                            dp[i - 1][j], // Remove
                            dp[i - 1][j - 1]); // Replace
        }
    }
 
    return dp[m][n];
}

/*
Time Complexity: O(m x n) 
Auxiliary Space: O(m x n)
*/

//TODO:Space optimized solution, memoization based solution
// Driver code
int main()
{
	// your code goes here
	string str1 = "sunday";
	string str2 = "saturday";

	cout << editDistDP(str1, str2, str1.length(),
					str2.length());

	return 0;
}


