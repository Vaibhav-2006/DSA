#include<stdio.h>
int main(){
	int i,n,j,temp;
	printf("\nenter the number of array elements\n");
	scanf("%d",&n);
	int a[n];
printf("\nenter the array:\n");
for(i=0;i<n;i++){
scanf("%d",&a[i]);
}

for(i=0,j=n-1;i<n/2;i++,j--){
	temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
printf("\nreverse array is:\n");
for(i=0;i<n;i++){
printf("\n%d\n",a[i]);	
}
return 0;
}
