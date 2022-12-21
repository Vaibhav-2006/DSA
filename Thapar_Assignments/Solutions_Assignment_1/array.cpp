#include<iostream>
#include<process.h>
using namespace std;
void display(int *a, int n);
int find(int *a,int size,int n){
	int i;
for(i=0;i<size;i++){
		if(a[i]==n)
			return i;
	}
	return -1;	
}
int* create(int *a,int &n)
{
	int i;
	cout<<"Enter number of array elements:"<<endl;
	cin>>n;
	a= new int[n];
	for(i=0;i<n;i++)
		cin>>a[i];
		display(a,n);
		return a;
}
void display(int *a, int n)
{
	if(a!=NULL){
	int i;
		cout<<"Array is:"<<endl;
	for(i=0;i<n;i++)
		cout<<a[i]<<endl;
	}
	else cout<<"Array is empty\n";
}
void insert(int *a, int &n)
{
	int d,i,l;
	cout<<"Enter the element to be added: "<<endl;
	cin>>d;
	if(a)
	{
		cout<<"Enter its index: ";
		cin>>l;
	if(l<=n)
	{
	n++;
	for(i=n-1; i>l; i--){
		a[i]=a[i-1];
	}
	a[l]=d;	
	}
	else cout<<"Entered index is out of range\n";
	}
	else
	{
		a=new int;
		*a=d;
		n++;
	}
}
void Delete(int *a,int &n)
{
	if(a){
	int p,i;
	cout<<"Enter the index location of element to be deleted"<<endl;
	cin>>p;
	if(p<n)
	{
	for(i=p;i<n-1;i++)
	a[i]=a[i+1];	
	n--;
	}
	else cout<<"Underflow\n";
	}
	else cout<<"Undeflow\n";	
}
int main(){
	int *a=NULL;
	int n=0,i,c;
while(1)
{
	cout<<"Enter your choice:";
	cin>>c;
switch(c){
case 1:
	a=create(a,n);
	break;
case 2:
		display(a,n);
		break;
	
case 3:
	insert(a,n);
	display(a,n);
	break;
case 4:
	Delete(a,n);
	display(a,n);
	break;
case 5:
	int s,k;
	cout<<"Enter the element u are searching for:"<<endl;
	cin>>s;
	k= find(a,n,s);
    (k==-1) ? cout << "Element is not present in array\n": cout << "Element is present at index " <<k<<"\n";
	break;
case 6:
	exit(0);
	break;
	default:
	cout<<"Invalid input";	
}
}
return 0;
}
