#include<stdio.h>
int main(){
	int n,i,x;
	printf("enter number of array elements: ");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++){
		a[i]=0;
		scanf("%d",&x);
		if(x==i)
		a[i]++;
	}
	for(i=0;i<n;i++){
		if(!(a[i])){
			printf("element at index %d is missing",i);
			break;
		}
	}
	return 0;
}
