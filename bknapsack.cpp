#include <stdio.h>
#include<iostream>
using namespace std;

int w[10],p[10],i,j,n,m;
float ratio[10],s=0.0;
int y[10],x[10],fp=-1,fw;

float bound(float cp,float cw,int k)
{
 float b = cp;
 float c = cw;
 for(i=k;i<=n;i++)
 {
   c = c+w[i];
   if( c < m)
    b = b +p[i];
   else
    return (b+(1-(c-m)/ w[i])*p[i]);
 }
 return b;
}

void bknapsack(int k,float cp,float cw)
{
 if(cw+w[k] <= m)
 {
   y[k] = 1;
   if(k <= n)
    bknapsack(k+1,cp+p[k],cw+w[k]);
   if(((cp+p[k]) > fp) && ( k == n))
   {
      fp = cp+p[k];
      fw = cw+w[k];
      for(j=0;j<=k;j++)
      x[j] = y[j];
   }
  }
  if(bound(cp,cw,k) >= fp)
  {
   y[k] = 0;
   if( k <= n)
   bknapsack(k+1,cp,cw);
   if((cp > fp) && (k == n))
   {
    fp = cp;
    fw = cw;
    for(j=0;j<=k;j++)
    x[j] = y[j];
   }
  }
}

void swap1(float *a, float *b)
{
    float t = *a;
    *a = *b;
    *b = t;
}
void swap2( int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void sort()
{
 for(i=0;i<n;i++)
 ratio[i] = p[i] / w[i];
 for(i=0;i<n-1;i++)
 {
   for(j=i+1;j<n;j++)
    {
      if(ratio[i]  < ratio[j])
      {
        swap1(&ratio[i],&ratio[j]);
        swap2(&p[i],&p[j]);
        swap2(&w[i],&w[j]);
      }
    }
 }
}

int main()
{
 printf("Enter total number of items= \n");
cin>>n;
 printf("Enter the maximum capacity= \n");
 cin>>m;
 for(i=0;i<n;i++)
 {
   cout<<"enter the weight of the item "<<i+1<<"=";
cin>>w[i];
 }
 for(i=0;i<n;i++)
 {
cout<<"Enter profit of item "<<i+1<<"=";   
cin>>p[i];
 }
 sort();
 bknapsack(0,0.0,0.0);
cout<<"\nThe added items are:";
 for(i=0;i<n;i++)
 if(x[i]==1)
 {
cout<<"\t"<<i+1;
   s=s+ p[i]*x[i];
 }

cout<<"\nMaximum Profit is="<<s;
 return 0;
}




