#include<iostream>
using namespace std;

void creatematrix(int G[20][20],int n,int e)
{
	int i,j;
	int cost, source, destination;
	for(i=0;i<e;i++)
	{
		cout<<"\n Enter source destination and cost:";
		cin>>source>>destination>>cost;
		G[source][destination]=cost;
		
	}
	for( i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(G[i][j]==0 && i!=j)
			G[i][j]=999;
		}
	}
}
void displaymatrix(int G[20][20],int n,int e)
{
	int i,j;
	for(int i=0;i<n;i++)
	{
		cout<<"\n";
		for(int j=0;j<n;j++)
		{
		cout<<"\t"<<G[i][j];
		}
	}
}
void allpairs(int cost[20][20], int A[20][20], int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			A[i][j]=cost[i][j];
		}
		
	}
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(A[i][j]>A[i][k]+A[k][j])
				A[i][j]=A[i][k]+A[k][j];
				else
				A[i][j]=A[i][j];
			}
		}
	}
	
	cout<<"\nThe shortest path between every pair of vertices are given as follows:\n";
	for(int i=0;i<n;i++)
	{
		cout<<"\n";
		for(int j=0;j<n;j++)
		{
			cout<<A[i][j]<<"\t";
		}
	}
}
int main()
{
	int i,j;
	int G[20][20],A[20][20],n,e;
	cout<<"\nEnter total number of vertices:";
	cin>>n;
	cout<<"\n Enter total number of edges:";
	cin>>e;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			G[i][j]=0;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			A[i][j]=G[i][j];
		}
		
	}
	creatematrix(G,n,e);
	displaymatrix(G,n,e);
	allpairs(G,A,n);
    return 0;
}
