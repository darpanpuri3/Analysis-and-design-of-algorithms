#include<iostream>
using namespace std;
void merge(int *arr, int low,int  mid, int high)
{
	int *temparr=new int[low+high-1];
	int i=low,j=mid+1, k=0;
	
	while(i<=mid && j<=high)
	{
		if(arr[i]<=arr[j])
		 {
		 	temparr[k++]=arr[i++];
		 	
		 }
		 else
		 {
		 	temparr[k++]=arr[j++];
		 }
	}
	while(i<=mid)
	temparr[k++]=arr[i++];
	
	while(j<=high)
	temparr[k++]=arr[j++];
	
	
	for(int i=low, k=0;i<=high;i++,k++)
	{
		arr[i]=temparr[k];
		}	
}


void mergesort(int *arr, int low, int high)
{
	if(low<high)
	{
			int mid=(low+high)/2;

		mergesort(arr, low, mid);
		mergesort(arr, mid+1,high);
		merge(arr,low,mid,high);
	}
}

int main()
{
	int n;
	cout<<"Enter number of elements you want to enter in the array:\n";
	cin>>n;
	int *arr=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	
	}
	cout<<"\n";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<"\t";
	
	}
	cout<<"\n";

mergesort(arr,0,n-1);
	for( int i=0;i<n;i++)
	{
		cout<<arr[i]<<"\t";
	
	}
	return 0;
}
