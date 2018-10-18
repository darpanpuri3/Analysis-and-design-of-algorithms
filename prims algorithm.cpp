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
void prims(int G[20][20],int n, int e)
{
	int visited[20];
	int src,dest;
	int i,j;
	int total=0;
	
	for(i=0;i<n;i++)
	{
		visited[i]=0;
	}
	cout<<"\nEnter source for finding minimum spanning tree:";
	cin>>src;
	visited[src]=1;
	e=0;
	while(e<n-1)
	{
	
	int min=999;
	for(i=0;i<n;i++)
	{
		if(visited[i]==1)
		{
			for(j=0;j<n;j++)
			{
				if(visited[j]!=1)
				{
					if(min>G[i][j])
					{
						min=G[i][j];
						src=i;
						dest=j;
					}
				}
			}
		}
	}
	visited[dest]=1;
	total=total+min;
	cout<<"Edge is from "<<src<<" to "<<dest<<" with cost="<<min<<"\n";
	e++;
}
cout<<"\nTotal cost is="<<total;	
	
}

int main()
{
	int i,j;
	int G[20][20],n,e;
	cout<<"\nEnter total number of vertices:";
	cin>>n;
	cout<<"\nEnter total number of edges:";
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
	prims(G,n,e);
    return 0;
}

