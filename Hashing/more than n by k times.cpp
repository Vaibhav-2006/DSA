/*A simple method is to pick all elements one by one. For every picked element, 
count its occurrences by traversing the array, if count becomes more than n/k, then print the element. 
Time Complexity of this method would be O(n^2).

A better solution is to use sorting. First, sort all elements using a O(nLogn) algorithm. 
Once the array is sorted, we can find all required elements in a linear scan of array. 
So overall time complexity of this method is O(nLogn) + O(n) which is O(nLogn).*/
#include<bits/stdc++.h>
using namespace std;

void printNbyK(int arr[],int n, int k)
{
	sort(arr, arr+n);
	int res=1, count=1, i=1;//count of occurrence of element at index 0 is taken 1.
	while(i<n)
	{
		while(i<n && arr[i]==arr[i-1])
		{
			count++;
			i++;
		}//when arr[i] != arr[i-1] we exit and check count of occurrence of arr[i-1].
		if(count > n/k)
			cout<<arr[i-1]<<" ";
			
		count=1;//Now count of this unequal element is taken to be 1.
		i++;//and we start from its next element
	}
}


/*
Hashing can also be an efficient and easy solution. With a good hash function, we can solve the above 
problem in O(n) time on average. Extra space required for hashing would be O(n).*/

void morethanNbyK(int arr[], int n, int k)
{
      // unordered_map initialization
    unordered_map<int, int> um;
  
    for(int i = 0; i < n; i++)
    {
        um[arr[i]]++;//if element exists then count is incremented else element is inserted with
    }				 //count=1.
    
      // Traversing the map
    for(auto i : um)
    {
          
        // Checking if value of a key-value pair
        // is greater n/k
        if (i.second > n/k)
        {
              
            // Print the key of whose value
            // is greater than x
            cout << i.first << " ";
        }
    }
}

//Above solution is efficient when n is small.

//Consider a situation in which n is very large and k is small. In this situation Hashmap will have to 
//store all distinct elements with their frequencies. In this situation an O(n*k) solution is better
//and as k is small O(n*k) is approximately linear. Also in this solution hashmap only stores 
//k-1 elements at max. 
//Consider the fact that at max there can only be K-1 elements with frequency > n/k. This can be proved
//using contradiction below:
//Suppose k elements have frequency> n/k then k*(n/k+1) elements are in array as frequency> n/k means frequency
//at least n/k+1. Also k*(n/k+1) is n+k which is > n ( the number of array elements. Also k cannot be 0 
//because of n/k term. So at max hash map will have k-1 elements. 
//This solution is very similar to Moore's voting algorithm wherein we first find the candidates and claim
//that if there is an element having frequency greater than n/k then it will surely be one of the candidates
//found by Moore's voting algorithm. We confirm if the chosen element has frequency > n/k in 2nd pass.

void O_nk_solution(int arr[], int n, int k)
{
	unordered_map<int, int> m;
	//Now we find candidates and store them in m.
	for(int i=0;i<n;i++)
	{
		if(m.find(arr[i])!=m.end())//if arr[i] exists in map already we increment its frequency.
		{
			m[arr[i]]++;
		}
		
		else if(m.size()<k-1)//if arr[i] is not present in map and there if free space in map
			m[arr[i]]++;//then we add arr[i] in map with frequency 1. Note that map becomes full
						//when its size is k-1
		
		else//if map is full and so arr[i] could not be added
		{	//then decrement the frequency of all other elements in map.
			for(auto i=m.begin();i!=m.end();)
			{
				i->second--;//decrementing frequency of all elements
				if(i->second==0)//if frequency of an element becomes 0 then remove it
				i=	m.erase(i);//so that we get space in map to add some other candidate but do not increment i as an 
				else ++i;//element has been deleted and we will start from exactly that place. Also it becomes
			}//extremely important that you return a valid address after erasing an element. You cant just increment some junk address that has been deleted.
		}	//YOU NEED TO return a valid address so i=	m.erase(i) is used because the i in parenthesis has been deleted and is invalid but erase will return a valid address to which will be assigned to i
			//and not incremented.
		for(auto e: m)//To see all elements in map.
			{
			cout<<e.first<<" "<<e.second<<endl;
			}
			cout<<"size:"<<m.size()<<endl;
		//Now we have the candidates in m
		//Now find if any candidate appears more than n/k times.
	}
	int count=0;
	for(auto i: m)
	{
		count=0;
		int x= i.first;
		for(int j=0;j<n;j++)
		{
			if(x==arr[j])
				count++;
		}
		if(count > n/k)
		cout<<x<<" ";
	}
}	

/*Time Complexity: O(nk) 
Auxiliary Space: O(k)
Generally asked variations of this problem are, find all elements that appear n/3 times or n/4 times in O(n)
time complexity and O(1) extra space.*/
int main()
{
	int arr[]={54 ,214 ,548 ,54 ,32 ,34 ,32};
	int n=sizeof(arr)/sizeof(arr[0]);
	int k=4; 
	O_nk_solution(arr,n,k);
}
