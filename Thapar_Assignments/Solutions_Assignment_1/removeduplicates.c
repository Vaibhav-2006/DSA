#include<stdio.h>
#include<stdlib.h>
int main(){
int *a,n,i,j,flag=0,k=0;
printf("\nenter no. of array elements:\n");
scanf("%d",&n);
a=(int*)malloc(n*sizeof(n));
printf("\nenter the array:\n");
for	(i=0;i<n;i++){
	scanf("%d",&a[i]);
}
printf("\non removing duplicates:\n");
for(i=0;i<n;i++){
	flag=0;
	for(j=i+1;j<n;j++){
		if(a[i]==a[j]){
		flag=1;
		break;
	}
	}
	if(flag==0)
	a[k++]=a[i];
}
realloc(a,k);
n=k;
for(i=0;i<n;i++){
	printf("%d\n",a[i]);
}
free(a);
return 0;
}
