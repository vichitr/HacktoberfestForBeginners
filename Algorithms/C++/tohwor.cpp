//Name: Ayus Das
//Email: ayusdas2000@gmail.com
/*
 *This code is the non recursive implementation of 
 * of tower of hanoi. The number of disks for the tower 
 * hanoi is taken as user input.
*/

#include<iostream>
using namespace std; 
//declares the stack to mimic recursion


int main()
{
	int n;
	cout<<"Enter the number of disks in the tower: ";
	cin>>n;
	char beg='A';
	char aux='B';
	char end='C';
	if(n<100){
	    int stn[100];
char stbeg[100];//This are the stacks for imitating recursive behaviour.
char staux[100];
char stend[100];
char stadd[100];
char add,temp,temp2;
	int top=-1;
	M:	
	    if(n==1)
	    {
		   cout<<beg<<" to "<<end<<endl;
		   goto O;
	    }
	top=top+1;
	stn[top]=n;
	stbeg[top]=beg;
	staux[top]=aux;
	stend[top]=end;
	stadd[top]='N';
	n=n-1;
	beg=beg;
	temp=aux;
	aux=end;
	end=temp;
	goto M;
	N:
		cout<<beg<<" to "<<end<<endl;
	top=top+1;
	stn[top]=n;
	stbeg[top]=beg;
	staux[top]=aux;
	stend[top]=end;
	stadd[top]='O';
	n=n-1;
	temp2=beg;
	beg=aux;
	aux=temp2;
	end=end;
	goto M;
	O:
		if(top==-1)
		return 0;
		n=stn[top];
		beg=stbeg[top];
		aux=staux[top];
		end=stend[top];
		add=stadd[top];
		top=top-1;
		if(add=='N')
		goto N;
		else if(add=='O')
		goto O;
		
		
		
	    

	}

	return 0;
}
