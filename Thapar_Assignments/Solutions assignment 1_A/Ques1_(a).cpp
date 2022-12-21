#include <iostream>
using namespace std;
class Diagonal
{
private:
int *A;
int n;
public:
Diagonal(int n)
{
this->n=n;
A=new int[n];
}
~Diagonal()
{
delete []A;
}
void Set(int i,int j,int x);
int Get(int i,int j);
void Display();
int GetDimension(){return n;}
};
void Diagonal::Set(int i,int j,int x)
{
if(i==j)
A[i]=x;
}
int Diagonal::Get(int i,int j)
{
if(i==j)
return A[i];
return 0;
}
void Diagonal::Display()
{
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
if(i==j)
cout<<A[i]<<" ";
else
cout<<"0 ";
}
cout<<endl;
}
}
int main()
{
int d;
cout<<"Enter Dimensions";
cin>>d;
Diagonal matrix(d);
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
