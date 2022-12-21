#include <iostream>
using namespace std;
class TriDiagonal
{
private:
int *A;
int n;
public:
TriDiagonal(int n)
{
this->n=n;
//If there is a matrix of order n then:
//The number of elements in the main diagonal is n and the number of elements in the
//lower and upper diagonal is n-1 each. Therefore the total no. of elements is 3n-2.
A=new int[3*n-2];
}
~TriDiagonal()
{
delete []A;
}
void Set(int i,int j,int x);
int Get(int i,int j);
void Display();
int GetDimension(){return n;}
};
void TriDiagonal::Set(int i,int j,int x)
{
if(i-j==1)
A[j]=x;
else if(i==j)
A[i+n-1]=x;
else if(i-j==-1)
A[n-1+n+i]=x;
}
int TriDiagonal::Get(int i,int j)
{
if(i==j)
return A[i+n-1];
else if(i-j==1)
return A[j];
else if(i-j==-1)
return A[n-1+n+i];
return 0;
}
void TriDiagonal::Display()
{
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
if(i==j)
cout<<A[i+n-1]<<" ";
else if(i-j==1)
cout<< A[j]<<" ";
else if(i-j==-1)
cout<< A[n-1+n+i]<<" ";
else
cout<<"0 ";
}
cout<<endl;
}
}
int main()
{
int d;
cout<<"Enter Dimensions:";
cin>>d;
TriDiagonal matrix(d);
int x;
cout<<"Enter All Elements:\n";
for(int i=0;i<d;i++)
{
for(int j=0;j<d;j++)
{
cin>>x;
matrix.Set(i,j,x);
}
}
matrix.Display();
return 0;
}
