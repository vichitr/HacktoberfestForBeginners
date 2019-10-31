// Name: Bhupendra Chauhan
//Email: chauhanbhupendra145@gmail.com
/*This is a program for Tower of Hanoi using recursion.
 * Number of Disks are taken as input from User.
*/

#include <stdio.h> 

void TOH(int, char, char, char);

// Driver Code
int main(){
	int n;    //Number of Disks
	flag:
	printf("Enter the number of disks : ");
    scanf("%d",&n);
    if(n>0){
    	printf("The sequence of moves involved in the Tower of Hanoi are :\n");
    	TOH(n, 'A', 'C', 'B');
    }
    else{
    	printf("Number of Disks should be a Natural Number\n");
    	goto flag;
    }

    return 0;
}


//Program Of Tower Of Hanoi
void TOH(int n,char From,char To,char Aux){
	if(n==1){
		printf("Move disk %d from Tower %c to Tower %c \n",n,From,To);
        return;
	}
	TOH(n-1,From,Aux,To);
	printf("Move disk %d from Tower %c to Tower %c \n",n,From,To);
	TOH(n-1,Aux,To,From);
}

