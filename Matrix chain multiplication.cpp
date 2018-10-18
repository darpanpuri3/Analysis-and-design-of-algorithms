#include<iostream>
using namespace std;
int m[20][20];
int s[20][20];

void matrix_chain_order(int *p,int n)
{
	for(int i=1;i<=n;i++)
	{
		m[i][i]=0;
	}
	for(int l=2;l<=n;l++)
	{
		for(int i=1;i<=(n+l-1);i++)
		{
			int j=i+l-1;
			m[i][j]=31999;
			for(int k=1;k<=(j-1);k++)
			{
				int q=m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]);
				if(q<m[i][j])
				{
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
}



int main()
{
	cout<<"\n Enter the number of matrices present in the multiplication:-";
	int n;
	cin>>n;
	int *arr=new int[n+1];
	cout<<"\nEnter dimensions:";
	for(int i=0;i<=n;i++)
	{
		cin>>arr[i];
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			m[i][j]=0;
			s[i][j]=0;
		}
	}
	
	matrix_chain_order(arr,n);
	for(int i=1;i<=n;i++)
	{
		cout<<"\n";
		for(int j=1;j<=n;j++)
		{
			cout<<m[i][j]<<"\t";
			
		}
	}
	return 0;
}
