//Redo this file
#include <bits/stdc++.h>
using namespace std; 

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition (int arr[], int low, int high,int lower) 
{ 
    int pivot = lower-1;  
    int i = (low - 1); 
  
    for (int j = low; j <= high - 1; j++) 
    { 
         
        if (arr[j] < pivot) 
        { 
            i++; 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    return i+1; 
} 
 
int main() 
{ 
	cout<<"Enter the lower value of range: ";
	cin>>lower;
    int arr[] = {3,4,9,5,2,1,8,6}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int i=quickSort(arr, 0, n - 1,lower);  
    for (; i < n; i++) 
        cout << arr[i] << " "; 
    return 0; 
} 
