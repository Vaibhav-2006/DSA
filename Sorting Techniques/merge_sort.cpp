#include <iostream>
using namespace std;


void merge(int arr[], int low, int high, int mid)
{
    int i, j, k, c[high-low+1];
    i = low;//can also be done using two arrays left and right.
    k = 0;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) 
            c[k++] = arr[i++];
        else 
            c[k++] = arr[j++];
    }
    while (i <= mid) {
        c[k++] = arr[i++];
    }
    while (j <= high) {
		c[k++] = arr[j++];
    }
    for (i =0; i < k; i++)  {
        arr[low+i] = c[i];
    }
}
void merge_sort(int arr[], int low, int high)
{
    int mid;
    if (low < high){
        mid=(low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,high,mid);
    }
}
int main()
{
    int num;
    cout<<"Enter number of elements to be sorted:";
    cin>>num;
    int *a=new int[num];
    cout<<"Enter "<<num<<" elements to be sorted:";
    for (int i = 0; i < num; i++) { cin>>a[i];}
    merge_sort(a, 0, num-1);
    cout<<"Sorted array:\n";
    for (int i = 0; i < num; i++)
    {
        cout<<a[i]<<"\t";
    }
    delete [] a;
}
