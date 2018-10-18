#include<iostream>
using namespace std;
void creatematrix(int G[20][20],int n,int e)
{
	int i,j;
	int cost, source, destination;
	for(i=1;i<=e;i++)
	{
		cout<<"\n Enter source destination and cost:";
		cin>>source>>destination>>cost;
		G[source][destination]=cost;
		G[destination][source]=cost;
	}
	for( i=1;i<=n;i++)
	{
		for(j=1;j<n;j++)
		{
			if(G[i][j]==0 && i!=j)
			G[i][j]=999;
		}
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
}
void multistage(int c[20][20],int k, int n, int *p)
{
	int *cost=new int[n+1];
	int *d=new int[n+1];
	
	
	
	cost[n]=0;
	int r;
	int min;
	for(int j=n-1;j>=1;j--)
	{
		min=1000;
		for( r=1;r<=n;r++)
		{
			if(c[j][r]!=0 && c[j][r]!=999)
			{
				if(c[j][r]+cost[r]<min)
				{
				   min=c[j][r]+cost[r];
				}
				
			}
			
		}
		cost[j]=min;
		d[j]=r;
		
	}
	p[1]=1;
	p[k]=n;
	for(int j=2;j<=k-1;j++)
	{
		p[j]=d[p[j-1]];
	}
	cout<<"\n\n\nIndividual minimum path costs are:-\n";
	for(int i=1;i<=n;i++)
	{
		cout<<i<<":-"<<cost[i]<<endl;
	}
}
int main()
{

int i,j;
	int G[20][20],n,e,k;
	cout<<"\nEnter total number of vertices:";
	cin>>n;
	cout<<"\n Enter total number of edges:";
	cin>>e;
	cout<<"\nEnter number of stages:";
	cin>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			G[i][j]=0;
		}
	}
	int *p=new int[n+1];
	
	creatematrix(G,n,e);
	displaymatrix(G,n,e);
	multistage(G,k,n,p);
    return 0;
}
