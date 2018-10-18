#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;
int main()
{
	float m;
	cout<<"Enter capacity of knapsack:";
	cin>>m;
	cout<<"\n";
	cout<<"Enter number of objects:";
	int n;
	cin>>n;
	cout<<"\n"<<"Enter values and weights:\n";
	float *p=new float[n]; //array of profits
	float *w=new float[n]; //array of weights
	float *r=new float[n]; //array of ratios
	float temp;
	float profit;
	int i=0;
	for( i=0;i<=n-1;i++)
	{
		cin>>p[i];
		cout<<"\t";
		cin>>w[i];
		cout<<"\n";
	}
	
	for( i=0;i<=n-1;i++)
	{
		cout<<p[i]<<"\t";
		cout<<w[i];
		cout<<"\n";
	}
	
	
		for( i=0;i<=n-1;i++)
	{
		r[i]=p[i]/w[i];
	}
	

for (i=0; i<n; i++) 
{
      for (int j=i+1;j<n;j++) 
	  {
         if (r[i]<r[j]) 
		 {
            temp = r[j];
            r[j] = r[i];  //sorting ratio
            r[i] = temp;
 
            temp = w[j];
            w[j] = w[i];  //sorting weight accordingly
            w[i] = temp;
 
            temp = p[j];
            p[j] = p[i]; //sorting profit accordingly
            p[i] = temp;
         }
      }
   }
   cout<<"\n";
   for(int i=0;i<n;i++)
   {
   	cout<<p[i]<<"\t"<<w[i]<<"\n"; //printing according to descending order of p/w ratio.
   }
   
   float cap=m; //copy of maximum capacity
   
   
   float *x=new float[n]; 
   
   for(i=0;i<n;i++)
   {
   	x[i]=0.0;  //initialising all values to 0.0
   }
   
for(i=0;i<n;i++)
    {
    	if(w[i]>cap)
    	{
		break;
	}
    	else
    	{
    	  x[i]=1.0;
    	  profit=profit+p[i]; //the greedy algorithm
    	  cap=cap-w[i];
		}
	}
	
	if(i<n)
	{
	x[i]=cap/w[i];
}
	
	profit=profit+(x[i]*p[i]);
	
	cout<<"\n"<<"The fraction of weights involved are:\n";
	
	for(i=0;i<n;i++)
	{
		cout<<x[i]<<" of "<<p[i]<<"\n";
	}
	cout<<"\n"<<"total profit="<<profit;
	
	
	
	return 0;
	
}
