//In this program an upper triangular matrix is stored in a column major form.
#include <stdio.h>
#include <stdlib.h>
struct Upper_Tri_Matrix
{
int *A;
int n;
};
void Set(struct Upper_Tri_Matrix *m,int i,int j,int x)
{
if(i<=j)
m->A[j*(j-1)/2+i-1]=x;
}
int Get(struct Upper_Tri_Matrix m,int i,int j)
{
if(i<=j)
return m.A[j*(j-1)/2+i-1];
else
return 0;
}
void Display(struct Upper_Tri_Matrix m)
{
int i,j;
for(i=1;i<=m.n;i++)
{
for(j=1;j<=m.n;j++)
{
if(i<=j)
printf("%d ",m.A[j*(j-1)/2+i-1]);
else
printf("0 ");
}
printf("\n");
}
}
int main()
{
struct Upper_Tri_Matrix m;
int i,j,x;
printf("Enter Dimension:");
scanf("%d",&m.n);
m.A=(int *)malloc(m.n*(m.n+1)/2*sizeof(int));
printf("Enter all elements\n");
for(i=1;i<=m.n;i++)
{
for(j=1;j<=m.n;j++)
{
scanf("%d",&x);
Set(&m,i,j,x);
}
}
printf("\n\n");
Display(m);
printf("\nTo show column major\n\n");
for(i=0;i<(m.n*(m.n+1))/2;i++)
printf("%d ",m.A[i]);
return 0;
}
