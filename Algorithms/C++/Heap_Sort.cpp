#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
using namespace std;

int N=0;

void Swap(int* x,int* y)
{
	*x+=*y;
	*y=*x-*y;
	*x-=*y;
}

void Min_Heapify(int*,int*);
int Disp_BHeap(int *,int);

int Build_Min_Heap(int Tree[],int Item,int N)
{
	int PAR,PTR;
	N++; PTR=N;
	Tree[N]=Item;
	while(PTR>1)
	{
		PAR=PTR/2;
		if(Tree[PAR]>Tree[PTR])
		{
			Min_Heapify(Tree,&PTR);
			/*Swap(&Tree[PAR],&Tree[PTR]);
			PTR=PAR;*/
		}
		PTR=PAR;
	}
	cout<<"Element "<<Item<<" inserted in the Heap Tree successfully!";
	getch();	return N;
}

void Min_Heapify(int Tree[],int *PTR)
{
	int PAR=*PTR/2;
	Swap(&Tree[PAR],&Tree[*PTR]);
	*PTR=PAR;
}

int delbheap(int tree[],int max,int item)
{
	item=tree[0];
	int left,right,ptr,last;
	last=tree[max];
	max=max-1;
	ptr=1;
	left=2;
	right=3;
	tree[ptr]=last;

	while(left<=max)
	{

		if(tree[ptr]>=tree[left]&&tree[ptr]>=tree[right])
		return 0;

		if(tree[right]<=tree[left])
		{
		Swap(&tree[ptr],&tree[left]);
		ptr=left;
		}
		else
		{
		Swap(&tree[ptr],&tree[left]);
		ptr=right;
		}

		left=2*ptr;
		right=left+1;
	}
	return item;
}

void heapsort(int tree[],int max)
{
	int i;
	int item;
	int n;
	n=max;

	for(i=1;i<=n;i++)
	Build_Min_Heap(tree,max,tree[i]);

	while(n>1)
	{
		item=delbheap(tree,max,item);
		tree[n+1]=item;
	}
}

int Heap_Sort(int *a,int beg,int end)
{
	int pivot=a[end];
	int i=beg-1, j,temp;
	
	for(j=beg;j<=end;j++)
	{
		if(a[j]<=pivot)
		{
			i++;
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}		
	temp=a[i+1];
	a[i+1]=a[end];
	a[end]=temp;
	return i+1;
}

int Disp_BHeap(int Tree[],int N)
{
	system("cls");
	if(N==0)
	{
		cout<<"ERROR - Underflow!";
		getch();	return N;
	}
	int x=0;
	while(x<N)
	{
		x++;
		cout<<x<<" : "<<Tree[x]<<endl;		
	}
	getch();	return N;
}

main()
{	
	int arr[100],n,res;
	do
	{
		system("cls");
		cout<<"\t1)\tInsert an element in to the Heap Tree\n\t2)\tDisplay the current Heap Tree\n\t0)\tExit\n\nYour choice: ";	cin>>res;
		switch(res)		
		{
			case 1:
				cout<<"Enter the value to be inserted: ";	cin>>n;
				N=Build_Min_Heap(arr,n,N);		break;
			case 2:
				N=Disp_BHeap(arr,N);	break;
			case 3:
				N=Heap_Sort(arr,1,N);
				N=Disp_BHeap(arr,N);
		}
	}while(res>0&&res<3);
}
