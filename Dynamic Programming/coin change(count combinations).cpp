#include <bits/stdc++.h>
using namespace std;


// Recursive C++ program for
// coin change problem.
// Returns the count of ways we can
// sum coins[0...m-1] coins to get sum n
int count(int coins[], int m, int sum)
{
	int res=0;
	// If sum is 0 then there is 1 solution
	// (do not include any coin)
	if (sum == 0)
		return 1;

	// If there are no coins and sum
	// is greater than 0, then no
	// solution exist
	if (m==0)
		return 0;

	// count is sum of solutions (i)
	// including coins[m-1] (ii) excluding coins[m-1]
	res=count(coins,m-1,sum);
	
	if(coins[m-1]<=sum)
		res+=count(coins,m,sum-coins[m-1]);
		
	return res;
}


int get_count( int coins[], int m, int sum )
{
    int dp[sum+1][m+1];
    
    for(int i=0; i<=m; i++)
    dp[0][i]=1;//sum 0 can be made in 1 way always
    
    for(int i=1; i<=sum;i++)
    {
    	dp[i][0]=0;//sum greater than 0 cannot be made in any way if no. of coins are 0
	}
	
	
    for (int i = 1; i <= sum; i++)
    {
        for (int j = 1; j <=m; j++)
        {
            dp[i][j]=dp[i][j-1];//without including coins[j-1]
            
            if(coins[j-1]<=i)
            dp[i][j]+=dp[i-coins[j-1]][j];//including coins[j-1] 
        }//note that in dp[i-coins[j-1]][j] second field remains j because we have infinite 
    }//supply of coins.
    return dp[sum][m];
}
// Time Complexity: O(mn)

//TODO:There is also a space optimized solution and a memoization based solution.
// Driver code
int main()
{
	int i, j;
	int arr[] = { 1, 2, 3 };
	int m = sizeof(arr) / sizeof(arr[0]);
	
	cout << " " << get_count(arr, m, 4);
	
	return 0;
}


