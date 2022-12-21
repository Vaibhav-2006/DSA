#include <stdio.h>
#include<string.h>
void swap(char *a,char *b)
{
	char temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void perm(char s[], int k)
{
	static int A[10]={0};
	static char Res[10];
	int i;
	if(s[k]=='\0')
	{
		Res[k]='\0';
		printf("%s\n",Res);
	}
	else
	{
		for(i=0;s[i]!='\0';i++)
		{
			if(A[i]==0)
			{
				Res[k]=s[i];
				A[i]=1;
				perm(s,k+1);
				A[i]=0;
			}
		}
	}
}
int main()
{
char s[10]="ABC\0";
perm(s,0);
}
