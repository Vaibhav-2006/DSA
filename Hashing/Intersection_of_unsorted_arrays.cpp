// CPP program to find intersection of unsorted arrays

#include <bits/stdc++.h>
using namespace std;
//Naive approach using two for loops:
void PrintIntersection(int arr1[], int arr2[], int m,int n)
{
	for( int i=0;i<m;i++)
	{
		bool found= false;
		for(int j=0; j<i;j++)
		{//checking if this element has appeared before
			if(arr1[j]==arr1[i])
			{
				found = true;
				break;
			}
		}
		if (found==true)
			continue;//if it has appeared then continue because that value has already been processed
			//otherwise if it is a distinct value from arr1 then search for it in the other array
		for(int j=0; j<n; j++)
		{
			if(arr1[i]==arr2[j])//if an occurrence is found in arr2 then print and break
				{//because arr2 may contain more occurrences of same element and we do not want duplicates 
					cout<<arr1[i]<<" ";//in intersection
					break;
				}
		}
	}
}
//Time complexity: O(N^2)
//Space complexity: O(1)

//Another solution:
//O(m*log m + n*log n) solution would be to sort the two arrays and use merging process of merge sort.
//If array is already sorted the we do not need to sort and it becomes a O(m+n) solution.
//Check sorting folder for that soltuion. It uses O(1) extra space.

//O(N) solution using hashing
void printIntersection(int arr1[], int arr2[], int n1,int n2)
{
    set<int> hs;
 
    // Insert the elements of arr1[] to set S
    for (int i = 0; i < n1; i++)
        hs.insert(arr1[i]);
 	//Now hs has distinct elements of arr1. hs[]=7 1 5 3 2 6 (in any order)
    for (int i = 0; i < n2; i++)
 		//Now pick an element from arr2 and search for it in hs. If found then print it and erase it from
 		//hs so that it is not printed again if picked element from arr2 appears again in arr2.
        
        if (hs.find(arr2[i]) != hs.end())
            {
            	cout << arr2[i] << " ";
            	hs.erase(arr2[i]);
			}
}
//Above code can also be implemented using 2 sets but this is better.
/*
The time complexity of this method is O(n1+n2) under the assumption that hash table search and insert operations 
take O(1) time. 
Space Complexity: O(n1) as at max arr1 will contain n1 distinct elements.
*/
// Driver Program
int main()
{
    int arr1[] = { 7, 1, 5, 3 , 5 , 2, 3, 6 };
    int arr2[] = { 3, 8, 3, 6, 20, 7, 3, 7, 6};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
 
    // Function call
    PrintIntersection(arr1, arr2, n1, n2);
 
    return 0;
}
