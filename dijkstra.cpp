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
int findminvertex(int *distance, int *visited, int n)
{
	int minvertex=-1;
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0 &&( minvertex==-1 || distance[i]<distance[minvertex]))
		{
			minvertex=i;
		   }   
	}
	return minvertex;
}

void dijkstra(int cost[20][20],int n)
{
	int *distance=new int[n];
	int *visited=new int[n];
	cout<<"\nEnter source vertex:";
	int source;
	cin>>source;
	
	for(int i=0;i<n;i++)
	{
		distance[i]=999;
		visited[i]=0;
	}
	distance[source]=0;
	
	for(int i=0;i<n-1;i++)
	{
		int minvertex=findminvertex(distance,visited,n);
		visited[minvertex]=1;
		for(int j=0;j<n;j++)
		{
			if(cost[minvertex][j]!=0 && visited[j]==0)
			{
				int dist=distance[minvertex]+cost[minvertex][j];
				if(dist<distance[j])
				distance[j]=dist;
			}
		}
	}
	
cout<<"\nThe shortest distance from the source '0' to all other vertices are:"<<endl;
for(int i=0;i<n;i++)
{
	cout<<i<<" "<<distance[i]<<endl;
}
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
	dijkstra(G,n);
   return 0;
}
