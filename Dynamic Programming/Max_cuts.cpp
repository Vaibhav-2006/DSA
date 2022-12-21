/* Dynamic Programming C++ implementation
Maximum cuts */
#include <bits/stdc++.h>
using namespace std;


//Recusrsive solution
int max_cuts(int n,int a,int b,int c)
{
	if(n<0)
	return -1;
	if(n==0)
	return 0;
	
	int res=max(max_cuts(n-a,a,b,c),
				max(max_cuts(n-b,a,b,c),max_cuts(n-c,a,b,c)));
			
	if(res==-1)
	return res;
	
	else return res+1;	
	
}
//Time complexity: O(3^n) 

//Tabulation
int Max_cuts(int n,int a,int b,int c)
{
	int rope[n+1];//0....n are sizes of rope
	rope[0]=0;//rope of 0 length can be cut in 0 ways
	
	for(int i=1;i<=n;i++)
	{
		rope[i]=-1;//-1 means it cannot be cut into size of a,b,c
		
		if(i>=a) rope[i]=max(rope[i],rope[i-a]);
		if(i>=b) rope[i]=max(rope[i],rope[i-b]);
		if(i>=c) rope[i]=max(rope[i],rope[i-c]);
		
		if(rope[i]!=-1)
		rope[i]++;
	}
	return rope[n];
}

//Time/Space complexity: theta(n) 
/* Driver program to test above function */
int main()
{
	int n=5,a=1,b=2,c=3;
	cout<<Max_cuts(n,a,b,c);
}

