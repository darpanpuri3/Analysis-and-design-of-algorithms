#include<stdio.h>
int arr[20];
int max=0,min=0;

void maxmin(int i, int j)
{
	int tempmax,tempmin,mid;
	if(i==j)
	{
		max=arr[i];
		min=arr[i];
	}
	else if(i==(j-1))
	{
		if(arr[i]>arr[j])
		{
			max=arr[i];
			min=arr[j];
		}
		else
		{
			max=arr[j];
			min=arr[i];
		}
	}
		else
		{
			mid=(i+j)/2;
			maxmin(i,mid);
			tempmax=max;
			tempmin=min;
			maxmin(mid+1,j);
			
			if(tempmax>max)
			max=tempmax;
			
			if(tempmin<min)
			min=tempmin;
		}
	}
	 

int main()
{
	printf("Enter size of the array\n");
	int size,i=0;
	scanf("%d",&size);
	printf("\n");
	for(i=0;i<size;i++)
	{
		
		scanf("%d",&arr[i]);
	
	}
	maxmin(0,size-1);
	printf("\nmax=%d\n",max);
		printf("min=%d\n",min);
return 0;
}
