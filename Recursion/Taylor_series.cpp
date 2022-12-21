//An easy but slow method to calculate taylor series
// Other methods are recursive method using static variables p and f
//iterative method
//Recursive and iterative methods based on horner's rule
#include<stdio.h>
int power(int m,int n)
{
if(n==0)
return 1;
return power(m,n-1)*m;
}
int fact(int n)
{
if(n==0)
return 1;
return fact(n-1)*n;
}
double e(int x, int n)
{
if(n==1)
return 1;
return (double)power(x,n-1)/(double)fact(n-1)+e(x,n-1);
}
//e^1(n=3)  =x^2/2!+x^1/1!+1;
int main()
{
printf("%lf \n",e(1,10));
return 0;
}
