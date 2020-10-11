def isMagic(num):
    sum=0
    while(num>0 or sum>9):
        if(num==0):
            num=sum
            sum=0
        sum=sum+num%10
        num=int(num/10)
    return True if (sum==1) else False
num=1234
if(isMagic(num)):
    print("Magic Number")
else:
    print("Not a Magic Number")
