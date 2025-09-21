/*#################################################################################
### PROGRAM TO IMPLEMENT HEAP SORT STRATEGY AND SORT A GIVEN NUMBER OF ELEMENTS ###
#################################################################################*/

#include<iostream>
#include<conio.h>
using namespace std;

int j=0, tree[100], A[100], sort[100];		

// UTILITY FUNCTION TO SWAP 2 ELEMENTS
void Swap(int*a, int*b)
{
	*a+=*b;
	*b=*a-*b;
	*a=*a-*b;
}

// FUNCTION TO BUILD THE HEAP STRUCTURE
void Build_BHeap(int item)
{
	j++;							// maintained index of the binary heap 
	int PTR=j, PAR, temp;			
	A[j]=item;
	while(PTR>1)					// loop runs till PTR points to other than the root node (index 1)
	{
		PAR=PTR/2;					// parent node is integer half of the current node (denoted by PTR)
		
		if(A[PAR]>A[PTR])			// checking min-heap property and fixing errors
		{
			Swap(&A[PAR],&A[PTR]);
			PTR=PAR;
		}
		else 
			return;
	}
}

// FUNCTION TO DELETE ELEMENTS FROM THE HEAP - THIS FUNCTION IS REQUIRED TO SORT THE ELEMENTS OF THE HEAP
int Del_BHeap()
{
	int LAST=A[j];
	j--;			// index decreases every time an element is deleted
	
	int PTR=1, LEFT=2, RIGHT=3;
	int K=A[PTR];
	A[PTR]=LAST;
	
	// deletion of elements from heap maintaining the property
	while(LEFT<=j)
	{
		if((A[LEFT]>=A[PTR])&&(A[RIGHT]>=A[PTR]))
			break;
		else if(A[LEFT]<=A[RIGHT])
		{
			Swap(&A[LEFT],&A[PTR]);
			PTR=LEFT;
		}
		else
		{
			Swap(&A[RIGHT],&A[PTR]);
			PTR=RIGHT;	
		}
		LEFT=2*PTR;
		RIGHT=LEFT+1;
	}
	return K;
}


int main()
{
	int size,i;
	cout<<"ENTER NO OF ELEMENTS: ";
	cin>>size;
	for(i=0;i<size;i++)
	{
		cout<<"\n ENTER ELEMENT "<<i+1<<": ";
		cin>>tree[i];
	}
	for(i=0;i<size;i++)
		Build_BHeap(tree[i]);
	for(i=0;i<size;i++)
	{
		int item=Del_BHeap();
		sort[i]=item;
	}
	cout<<"\n\nThe sorted array elements are given below:- \n";
	for(i=0;i<size;i++)
	{
		cout<<sort[i];
		if(i<size-1)
			cout<<" < ";
	}
	return 0;
}
