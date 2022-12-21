#include<iostream>
  using namespace std;
  int i=0;
   int power(int x, int n)
  
   { 
    i++;
   if (n==0)
       return 1;
     else if (n==1)
       return x;
     else if ((n%2)==0)
       return power(x, n/2)*power(x, n/2);
     else
       return x*power(x, n/2)*power(x, n/2);
}

int main()
{
	power(2,16);
	cout<<i;
}
