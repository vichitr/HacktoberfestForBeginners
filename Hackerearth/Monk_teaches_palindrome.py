t = int(input())

while t>0:
    a = input()
    if a==a[::-1]:
        if len(a)%2==0:
            print('YES EVEN')
        else:
            print('YES ODD')
    else:
        print('NO')
    t-=1
