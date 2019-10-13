dp=[]
for i in range(1000,9000):
	k1 = i%10
	k2 = (i//10)%10
	k3 = (i//100)%10
	k4 = i//1000
	d={}
	d[k1]=0
	d[k2]=0
	d[k3]=0
	d[k4]=0
	if len(d)==4:
		dp.append(i)
dp.append(9012)
y = int(input())
for i in dp:
	if i>y:
		print(i)
		break
