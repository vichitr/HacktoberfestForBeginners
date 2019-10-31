#include <stdio.h>
inline int scan()
{
    char c = getchar_unlocked();
    int x = 0;
    while(c<'0'||c>'9'){
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+c-'0';
        c=getchar_unlocked();
    }
    return x;
}
int main()
{
    int x,y,t;
    t=scan();
    while(t--)
    {
        x=scan();
        y=scan();
        int ans=-1;
        if(x==y)
        ans=1;
        if(ans!=1)
    	for(int i = 2; i < 21; i++)
    	{
    	    if(pow(1.0*x / i, i) >= y)
    	    {
    		    ans=i;
    		    break;
            }
    	}
    	printf("%d\n",ans);
    }
}
