#include <iostream>
using namespace std;
int binarySearch(int a[], int l, int r, int x)
{
    if (r >= l) {
        int mid = (l+r)/ 2;
        if (a[mid] == x)
            return mid;
        if (a[mid] > x)
            return binarySearch(a,l,mid-1,x);
        return binarySearch(a, mid+1,r,x);
    }
    return -1;
}
  
int main()
{
	int size,x,k;
    cout<<"Enter size of array:";
	cin>>size;
	int a[size];
	cout<<"\nEnter a sorted array:";
	for(k=0;k<size;k++)
	cin>>a[k];
    cout<<"\nenter element you want to search for:";
	cin>>x;
    k= binarySearch(a, 0, size - 1, x);
    (k==-1) ? cout << "\nElement is not present in array": cout << "\nElement is present at index " <<k;
    return 0;
}
