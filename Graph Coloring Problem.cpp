#include<iostream>
using namespace std;

int G[20][20];

void creatematrix(int G[20][20],int n,int e)
{
	int i,j;
	int cost, source, destination;
	for(i=1;i<=e;i++)
	{
		cout<<"\n Enter source destination:";
		cin>>source>>destination;
		G[source][destination]=1;
		G[destination][source]=1;
	}
	
}
void displaymatrix(int G[20][20],int n,int e)
{
	int i,j;
	for(int i=1;i<=n;i++)
	{
		cout<<"\n";
		for(int j=1;j<=n;j++)
		{
		cout<<"\t"<<G[i][j];
		}
	}
	cout<<"\n\n";
}
void nextvalue(int k, int *x, int m, int n)
{
	int j;
	do
	{
		x[k]=(x[k]+1)%(m+1);
		if(x[k]==0)
		return;
		for( j=1;j<=n;j++)
		{
			if((G[k][j]!=0) && (x[k]==x[j]))
			break;
		}
		if(j==(n+1))
		return;
	}while(1);
}
void mcoloring(int n, int m, int k, int *x)
{
	do
	{
		nextvalue(k,x,m,n);
		if(x[k]==0)
		{
			return;
		}
		if(k==n)
		{
			for(int i=1;i<=n;i++)
			{
				cout<<x[i]<<" ";
			}
			cout<<"\n";
		}
		else
		{
			mcoloring(n,m,k+1,x);
		}
	}while(1);
}

int main()
{
	int m,n,e;
	cout<<"\nEnter the number of nodes in the graph:";
	cin>>n;
	cout<<"\nEnter number of edges in the graph:";
	cin>>e;
	cout<<"\n Enter the number of colors in the graph:";
	cin>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			G[i][j]=0;
		}
	}
	int *x=new int[n+1];
	creatematrix(G,n,e);
	displaymatrix(G,n,e);
	mcoloring(n,m,1,x);
	return 0;
}
