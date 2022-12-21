#include <bits/stdc++.h>
using namespace std;

int **dp;

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs_recursive( string &X, string &Y, int m, int n )
{
	if (m == 0 || n == 0)
		return 0;
	if (X[m-1] == Y[n-1])
		return 1 + lcs_recursive(X, Y, m-1, n-1);
	else
		return max(lcs_recursive(X, Y, m, n-1), 
				   lcs_recursive(X, Y, m-1, n));
}

//Memoization
/* A Top-Down DP implementation of LCS problem */
int lcs(string X, string Y, int m, int n)
{
	
	if(dp[m][n]==-1)
{
    if (m == 0 || n == 0)
        dp[m][n]=0;
    else if (X[m - 1] == Y[n - 1])
        dp[m][n] = 1 + lcs(X, Y, m - 1, n - 1);
 	else
    	dp[m][n] = max(lcs(X, Y, m, n - 1),
                       lcs(X, Y, m - 1, n));
}
    return dp[m][n];
}
//Time Complexity : O(mn) ignoring recursion stack space

//Tabulation approach
int lcs_tabulation(string X, string Y, int m, int n)
{
    // intitalizing a matrix of size (m+1)*(n+1)
    int L[m + 1][n + 1];
 
    /* Following steps build L[m+1][n+1] in bottom up fashion. Note
        that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
        
    for(int i=0; i<=m; i++)
    {
    	L[i][0]=0;
	}
	
	 for(int j=0; j<=n; j++)
    {
        L[0][j]=0;
	}	
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        { 
            if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
 
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
 
    // L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1]
    return L[m][n];
}

/* Driver code */
int main()
{
	string X = "AGGTAB";
	string Y = "GXTXAYB";
	int m=X.length();
	int n=Y.length(); 
	dp= new int*[m+1];
	for(int i=0;i<=m;i++)
	{
	dp[i]=new int[n+1];
	for(int j=0;j<=n;j++)
	{
		dp[i][j]=-1;
	}}
	
	cout<<"Length of LCS is "<< lcs_tabulation( X, Y, m, n) ;
	
	return 0;
}

