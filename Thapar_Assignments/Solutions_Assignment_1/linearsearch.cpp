#include<iostream>
using namespace std;
int find(int a[],int size,int n){
	int i;
for(i=0;i<size;i++){
		if(a[i]==n)
			return i;
	}
	return -1;	
}
int main(){
	int x,k,size;
	cout<<"Enter size of array:";
	cin>>size;
	int a[size];
	for(k=0;k<size;k++)
	cin>>a[k];
	cout<<"enter element you want to search for:";
	cin>>x;
	k=find(a,size,x);
	if(k==-1){
		cout<<"element not found";
	}
	else 
	cout<<x<<" is present at "<<k;
	return 0;
}
