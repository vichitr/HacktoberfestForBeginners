T=long(input())
for i in range(T):

   num = long(input())
   z=[0,1]

   for j in range(2,61):
     b=((z[j-2])%10+(z[j-1])%10)%10
     z.append(b)


   count=0
   while(num!=1):
       num=num/2
       count=count+1

   a=2**count
   a=a%60


   print(z[a-1])
