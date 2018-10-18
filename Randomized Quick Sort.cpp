#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

int partition(int *arr, int low, int high)
{
	srand(time(0));
	int random=rand()%(high-low+1)+low;
	
	int temp=arr[random];
	arr[random]=arr[low];
	arr[low]=temp;
	
	int pivot=arr[low];
	int first=low, last=high;
while(first<last)
{
	while(pivot>=arr[first] )
{
	first++;
}	
while(pivot<arr[last]  )
{
	last--;
}
if(first<last)
{
	int temp=arr[first];
	arr[first]=arr[last];
	arr[last]=temp;
}
}

arr[low] = arr[last];
 arr[last] = pivot;
 return last;

}
void quicksort(int *arr, int low, int high)
{ 

	if(low<=high)
	{
		
	int pindex=partition(arr, low,high);

		quicksort(arr,low, pindex-1);
		quicksort(arr, pindex+1,high);
	}
}


int main()
{
	int n;
	cout<<"Enter number of elements you want to enter in the array:\n";
	cin>>n;
	int *arr=new int[n];
	cout<<"\n";
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

quicksort(arr,0,n-1);
	for( int i=0;i<n;i++)
	{
		cout<<arr[i]<<"\t";
	
	}
	return 0;
}



