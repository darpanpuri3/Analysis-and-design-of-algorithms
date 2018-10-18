#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
int temp=0;

void heapify(int *arr, int n)

{ 
int i=n/2;
if(n%2==0)
{
	arr[(2*i)+1]=0;
}
	
	for(int i=n/2;i>=1;i--)
	{
		if(arr[(2*i)+1]>=arr[i])
		{
		temp=arr[(2*i)+1];
		arr[(2*i)+1]=arr[i];
		arr[i]=temp;
		
		}
		if(arr[(2*i)]>=arr[i])
		{
		temp=arr[(2*i)];
		arr[(2*i)]=arr[i];
		arr[i]=temp;
		
		}
	}
}

void maxheap(int *arr, int n)
{
	
	for(int i=n/2;i>=1;i--)
	{
	
	heapify(arr,n);
}
}
void heapsort(int *arr, int n)
{
	
	int *arr1=new int[n];
	int k=0;
	for(int i=n;i>=1;i--)
	{
		maxheap(arr,i);
		
		temp=arr[1];
		arr[1]=arr[i];
		arr[i]=temp; 
		
		arr1[k++]=arr[i];
		delete(&arr[i]);
	}
	for(int i=0;i<n;i++)
	{
		cout<<arr1[i]<<"\t";
	}
	
}



	
	

int main()
{
	srand(time(0));
	cout<<"Enter number of elements of the array:\n";
	int n;
	
	cin>>n;
	int *arr=new int[n];
	for(int i=1;i<=n;i++)
	{
		arr[i]=rand()%n;
	}
	
	for(int i=1;i<=n;i++)
	{
		cout<<arr[i]<<"\t";
	}
	cout<<"\n";
	
	
	heapsort(arr,n);
	
	
	
	
}
