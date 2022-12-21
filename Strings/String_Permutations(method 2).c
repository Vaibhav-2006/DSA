#include <stdio.h>
#include<string.h>
void swap(char *a,char *b)
{
	char temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void perm(char s[], int l, int h)
{
	int i;
	if(l==h)
	{
		printf("%s\n",s);
	}
	else
	{
		for(i=l;i<=h;i++)
	{
		printf("%d %d %d\n",i,l,h);
		swap(&s[l],&s[i]);
		perm(s,l+1,h);
		swap(&s[l],&s[i]);
	}
	}
}
int main()
{
char s[10]="ABC\0";
perm(s,0,strlen(s)-1);
}
