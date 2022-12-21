//In array sorted in ascending order we would get exactly 1 leader
//10 20 30 40 50, only 50 is leader
//but in descending order we would get all unique elements
//10 20 20 30 40, we would get 10 20 30 40 

#include<iostream>
using namespace std;
//Naive approach
/*C++ Function to print leaders in an array */
void printLeaders(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int j;
		for (j = i+1; j < size; j++)
		{
			if (arr[i] <=arr[j])
				break;
		}
		if (j == size) // the loop didn't break
			cout << arr[i] << " ";
}
}

//Time Complexity: O(n*n)

//Method 2

/* C++ Function to print leaders in an array */
void printLeaders(int arr[], int size)
{
    int max_from_right =  arr[size-1];
 
    /* Rightmost element is always leader */
    cout << max_from_right << " ";
     
    for (int i = size-2; i >= 0; i--)
    {
        if (max_from_right < arr[i])
        {          
            max_from_right = arr[i];
            cout << max_from_right << " ";
        }
    }   
}
//Time Complexity: O(n)
//This would print the elements in right to left fashion..
//We can actually store these elements in an aux array and then print from n-1 to 0 in aux array
//to get leaders in left to right fashion.

int main()
{
	int arr[] = {16, 17, 4, 3, 5, 2};
	int n = sizeof(arr)/sizeof(arr[0]);
	printLeaders(arr, n);
	return 0;
}
