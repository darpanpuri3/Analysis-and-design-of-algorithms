#include<iostream>
#include<stdlib.h>
using namespace std;

int knapsack(int n, int tw, int *weight, int *p)
{
	int k[n+1][tw+1];
	int i,w;
	for( i=0;i<=n;i++)
	{
		k[i][0]=0;
	}
	for(w=0;w<=tw;w++)
	{
		k[0][w]=0;
	}
	for(i=1;i<=n;i++)
	{
		for(w=1;w<=tw;w++)
		{
			if(weight[i]<=w)
			{
				k[i][w]=max(k[i-1][w],k[i-1][w-weight[i]]+p[i]);
			}
			else
			{
				k[i][w]=k[i-1][w];
			}
		}
	}
	
	return k[n][tw];
}

int main()
{
	int i,j,temp;
	cout<<"\nEnter number of objects:";
	int n; cin>>n;
	int tw; int tp;
	int *weight=new int[n+1];
	int *profit=new int[n+1];
	
	weight[0]=profit[0]=0;
	cout<<"\nEnter total weight:";
	cin>>tw;
	cout<<"\nEnter the weights with the corresponding profits:";
	cout<<"\n";
	for( i=1;i<=n;i++)
	{
		cout<<"Enter weight:";
		cin>>weight[i];
		cout<<"Enter profit:";
		cin>>profit[i];
		cout<<"\n";
	}
	for (i=0; i<=n; i++)
    {
        for (j = 0; j <=(n - i - 1); j++)
        {
            if (weight[j] > weight[j + 1])
            {
                temp = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = temp;
                
                 temp = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = temp;
                
                
            }
        }
    }
    cout<<"\n";
    tp=knapsack(n,tw, weight, profit);
	cout<<"\nThe maximum profit that can be earned is="<<tp;
}
