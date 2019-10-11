fact=[0]*(100)
fact[0]=1
fact[1]=1 
for i in range(2,100):
    fact[i]=i*fact[i-1]
n=int(input())
if n<100:
    print(fact[n])
else:
    print("big no")
