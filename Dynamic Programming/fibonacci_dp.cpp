#include <bits/stdc++.h>
using namespace std;

int *dp,res;//global variable

//Memoization
int fib_helper(int n)
{
	if(dp[n]==-1)
	{
	if (n <= 1)
		res=n;
	
	else
		res=fib_helper(n-1)+fib_helper(n-2);
	
	dp[n]=res;
	}
	return dp[n];
}

int fib(int n)
{
	dp= new int[n+1];
	for(int i=0;i<=n;i++)
		dp[i]=-1;
	return fib_helper(n);	
}

//Tabulation

int fibonacci(int n)
{
	int fib[n+1];
	fib[0]=0,fib[1]=1;
	for(int i=2; i<=n;i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
	}
	return fib[n];
}
// Driver Code
int main()
{
	int n = 9;
	cout << fib(n)<<endl;
	
	return 0;
}

