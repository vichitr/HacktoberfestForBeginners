#include<stdio.h>
int main()
{int option,i,j,res;
 printf("1.addition\n 2.substraction\n 3. multiplication\n 4.division\n");
 printf("enter your choise\n");
 scanf("%d",&option);
 printf("enter number 1\n");
 scanf("%d",&i);
 printf("enter number 2\n");
 scanf("%d",&j);
 switch(option)
{case 1: res=i+j;
   	 printf("result is= %d",res);
  	 break;
 case 2: res=i-j;
	 printf("result is=%d",res);
	 break;
 case 3: res= i*j;
 	 printf("result is=%d",res);
	 break;
 case 4: res=i/j
	 printf("result is=%d",res);
	 break;
 default:printf("enter only from 1-4);
}
return 0;
}