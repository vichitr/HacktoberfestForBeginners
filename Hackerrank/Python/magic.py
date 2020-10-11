def isMagic(n):
    sum=0
    while(n>0 or sum>9):
        if(n==0):
            n=sum
            sum=0
        sum=sum+n%10
        n=int(n/10)
    return True if (sum==1) else False
n=1234
if(isMagic(n)):
    print("Magic Number")
else:
    print("Not a Magic Number")
