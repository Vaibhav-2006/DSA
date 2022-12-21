#include<stdio.h>
int main(){
		int n,m,i,j,k,sum=0;
	printf("\nenter the number of rows:\n");
	scanf("%d",&n);
	printf("\nenter the number of columns:\n");
	scanf("%d",&m);
	int a[n][m],b[n][m],d[n][m];
	printf("\nenter array elements:\n");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
		printf("\narray element a[%d][%d]:",i,j);
		scanf("%d",&a[i][j]);
	}
}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
		printf("%d\t",a[i][j]);
	}
	printf("\n");
}
printf("another matrix:");
printf("\nenter array elements:\n");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
		printf("\narray element b[%d][%d]:",i,j);
		scanf("%d",&b[i][j]);
	}
}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
		printf("%d\t",b[i][j]);
	}
	printf("\n");
}
printf("\non multiplying two arrays we get:\n");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			for(k=0;k<n;k++){
				sum=sum+a[i][k]*b[k][j];
			}
				d[i][j]=sum;
				sum=0;
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
		printf("%d\t",d[i][j]);
	}
	printf("\n");
}
return 0;
}
