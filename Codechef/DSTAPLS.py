'''
Author:Hemant Rana
Problem:Distribute Apples | DSTAPLS
Contest:August Challange 2019 Division 2 
'''
t=int(input())

for i in range(0,t):

    vals=input()
    vals=vals.split(" ")
    n=int(vals[0])
    k=int(vals[1])

    if(k==n):
        if(k==1):
            print("NO")
        else:
            print("YES")
    else:
        if(n%(k**2)==0):
            print("NO")
        else:
            print("YES")
