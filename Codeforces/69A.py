x,y,z=0,0,0
for _ in range(int(input())):
	a = list(map(int,input().split()))
	x+=a[0]
	y+=a[1]
	z+=a[2]
if x==0 and y==0 and z==0:
	print("YES")
else:
	print("NO")
