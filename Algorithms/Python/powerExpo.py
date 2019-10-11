def power(x,y):
    res=1 
    while y>0:
        if y&1:
            res=(res*x)
        y=y>>1 
        x=(x*x)
    return res 
a,b=map(int,input().split())
print("a^b = ",power(a,b))
