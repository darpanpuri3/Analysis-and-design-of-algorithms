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
		G[destination][source]=cost;
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
int kruskals(int G[20][20],int n)
{
	int min=999;
	int *visited=new int[n];
	int e=0;
	int total=0;
	int i,j;
	int src,dest;
	
	for(i=0;i<n;i++)
	{
	  visited[i]=0;	
	}
	
	while(e<n-1)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(visited[i]==1 && visited[j]==1)
				{continue;}
				else
				{
					if(G[i][j]!=0 && G[i][j]<min)
					{
						min=G[i][j];
						src=i;
						dest=j;
					}
				}
			}
		}
		visited[src]=1;
	visited[dest]=1;
	cout<<"\n An edge from "<<src<<" to "<<dest<<" with cost="<<min;
	total=total+min;
	min=999;
	e++;
	}
	
	return total;
}
int main()
{
	int i,j;
	int G[20][20],n,e;
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
	creatematrix(G,n,e);
	displaymatrix(G,n,e);
	int mincost=kruskals(G,n);
	cout<<"\n The minimum cost of the spanning tree="<<mincost;
    return 0;
}
