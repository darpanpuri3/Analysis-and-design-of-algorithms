#include<iostream>
#include<stdlib.h>
using namespace std;

place(int *x,int k, int i)
{
	int j;
	for(j=1;j<=(k-1);j++)
	{
		if((x[j]==i) || (x[j]-i)==(j-k) || (x[j]-i)==(k-j))
		{
			return -1;
		}
	}
	return 1;
}
void nqueens(int *x,int k, int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(place(x,k,i)==1)
		{
		   x[k]=i;
		   if(k==n)
		   {
		   	for(int i=1;i<=n;i++)
		   	{
		   		cout<<x[i]<<" ";
			   }
		   }
		   else
		   nqueens(x,k+1,n);
		}
	}
}

int main()
{
	int n;
	cout<<"\nEnter the number of queens:";
	cin>>n;
	int *x=new int[n+1];
	nqueens(x,1,n);
	return 0;
}
