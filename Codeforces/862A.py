n,x=map(int,raw_input().split())
a=map(int,raw_input().split())
if x in a:
	c=1
	for i in range(0,x):
		if i not in a:
			c+=1
	print c
else:
	c=0
	for i in range(0, x):
		if i not in a:
			c+=1
	print c
