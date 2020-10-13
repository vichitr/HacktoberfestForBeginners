//October Challenge 2020 Division 2
//Problem: Covid run

#include <iostream>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--)
    {
        long long int N,K,X,Y,i;
        cin>>N>>K>>X>>Y;
        int j=0,flag=0;
        for(i=1;i<=N;i++)
        {
            if(Y>N)
            {   
                flag=0;
            }
            else
            {
                if((X+K*i)%N==Y)
                {
                    flag=1;
                    j--;
                }
            }
        }
        if(flag==0)
            cout<<"NO\n";
        else
            cout<<"YES\n";
        
    }
	return 0;
}