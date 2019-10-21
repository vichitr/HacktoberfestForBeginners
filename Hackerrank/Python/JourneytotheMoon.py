MAXN = 100000+5
MAXI = 1000000+5

n,i = input().split(' ')

n = int(n)
I = int(i)

a = [-1 for i in range(0,n)]
co = [1 for i in range(0,n)]

def F(x):
    t = x
    while ( a[t] != -1 ):
        t = a[t]
    if ( ( a[x] != -1 ) & ( a[x] != t ) ):
        a[x] = t
        #co[t] += co[x]
    return t

def U(x,y):
    fx = F(x)
    fy = F(y)
    #print("!! %d %d"%(fx,fy))
    if ( fx != fy ):
        a[fx] = fy
        co[fy] += co[fx]
   
    
for i in range(0,I):
    x,y = input().split(' ')
    x = int(x)
    y = int(y)
    U(x,y)

          
l = []
c = 0
A = 0

for i in range(0,n):
    if ( a[i] == -1 ):
        l.insert(c,co[i])
        A += co[i]
        c = c+1

#print(l)
ans = 0
for i in range(0,c):
    ans += l[i]*(A-l[i])

ans = ans//2

print(ans)
