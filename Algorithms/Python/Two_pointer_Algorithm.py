l=[1,2,3,4,5,6,7,8,9,10]
i=0
j=len(l)-1
while(i<j):
    temp=l[i]
    l[i]=l[j]
    l[j]=temp
    i+=1
    j-=1
for k in l:
    print(k,end=",")