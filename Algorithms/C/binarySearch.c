//program to perform binary search
//By me fiirst must be 0 or else first element will not be uncountered.
#include<stdio.h>
#include<conio.h>
int main()
{
	int n,arr[100],i,search,flag=0;
	printf("Enter the size of the array \n");
	scanf("%d",&n);
	printf("Enter  the array \n");
	for (i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter the no. to searched \n");
	scanf("%d",&search);
	int first =0,last=n-1,mid=0,pos=0;
	while(first<=last)
	{
		mid=(last+first)/2;
		if(arr[mid] == search)
		{
			flag=1;
			pos=mid;
			break;
		}
		if(arr[mid]<search)
		{
			first=mid+1;
		}
		else
		{
			last=mid-1;
		}
	}
	if (flag==1)
	{
		printf("Search is successful");
	}
	else
	{
		printf("Element not found");
	}
}
