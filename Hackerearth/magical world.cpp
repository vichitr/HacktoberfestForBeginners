#include<iostream>
using namespace std;
int isPrime(int n)
{
    if(n == 1 || n == 2)
	 return 1;
    if(n%2 == 0)
	 return 0;    
    else
	 {
        for(int i=3; i <= n/2; i++)
		 {
       		 if(n%i == 0)
			 {
           		 return 0;
            	 break;
             }
          }
      }
   return 1;
}
int findPrime(int num, int ctr)
{
    if(isPrime(num))
	 return num;
    else
	 {
        ctr++;       
        if(isPrime(num-ctr) && (num-ctr) > 64 ) 
		{
            return num-ctr; 
        }
        else if(isPrime(num+ctr) && (num+ctr) < 123)
		 return num+ctr;
        
        else {
            findPrime(num, ctr);
        }
        
        
       
    }
}
int main()
{
    int t;
    int l, num;
    char str[500];
	cin>>t;
    for(int i=0; i < t; i++) 
	{
		cin>>l>>str;
        for(int j=0; j < l; j++) {
            num = str[j];
            if(num < 65) num = 65;
           cout<<(char)findPrime(num, 0);
        }
        cout<<"\n";
	  }
    
    return 0;
}


