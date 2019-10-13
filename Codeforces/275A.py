t=[]
for i in range(3):
	a=[]
	for j in range(3):
		a.append(0)
	t.append(a)
for i in range(3):
	k = list(map(int,input().split()))
	for j in range(3):
		t[i][j]+=k[j]
		if i-1>=0:
			t[i-1][j]+=k[j]
		if i+1<3:
			t[i+1][j]+=k[j]
		if j-1>=0:
			t[i][j-1]+=k[j]
		if j+1<3:
			t[i][j+1]+=k[j]
		
for i in range(3):
	for j in range(3):
		if t[i][j]%2==0:
			print("1",end="")
		else:
			print("0",end="")
	print("")
