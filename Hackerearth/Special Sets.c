#include <stdio.h>
int main()
{
    long long int n,r,max,product,mod=1000000007,result=0,i;
    scanf("%lld",&n);
    if(n%2)
        max=(n+1)/2;
    else
        max=(n+2)/2;
    for(r=1;r<=max;++r)
    {
        product=n-2*r+2;
            
            for(i=n-2*r+3;i<=n-r+1;++i)
                product=(product*(i%mod))%mod;
            result=(result+product)%mod;
    }
    printf("%lld",result);
    return 0;
}
