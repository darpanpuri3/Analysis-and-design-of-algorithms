#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
int c[20][20];
char b[20][20];

void print_lcs(char b[20][20],char *x, int i, int j)
{
	if(i==0 || j==0)
	{
	cout<<x[i];
	return;
	}
	
	if(b[i][j]=='*')
	{
		print_lcs(b,x,i-1,j-1);
		cout<<x[i];
	}
	else if(b[i][j]=='!')
	{
		print_lcs(b,x,i-1,j);
	}
	else
	{
		print_lcs(b,x,i,j-1);
	}
	 
}
void lcs_length(char *x,char *y)
{
	
	int i,j;
	int m=strlen(x);
	int n=strlen(y);
	for(int i=1;i<=m;i++)
	{
		c[i][0]=0;
	}
	for(int j=1;j<=n;j++)
	{
		c[0][j]=0;
	}
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(x[i]==y[j])
			{
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]= '*';
			}
			else
			{
				if(c[i-1][j]>=c[i][j-1])
				{
					c[i][j]=c[i-1][j];
					b[i][j]='!';
				}
				else
				{
					c[i][j]=c[i][j-1];
					b[i][j]='^';
				}
			}
		}
	}
}




int main()
{
	char s1[20],s2[20];
	cout<<"\n Enter the first string:";
	cin>>s1;
	cout<<"\n Enter the second string:";
	cin>>s2;
    int m=strlen(s1);
	int n=strlen(s2);
	lcs_length(s1,s2);
	print_lcs(b,s1,m,n);
	

	return 0;

}
