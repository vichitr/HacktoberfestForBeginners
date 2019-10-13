import math
n=int(raw_input())
p=int(math.sqrt(n))
if p*p==n:
	print 4*p
else:
	k=n/(p+1)
	l=n%(p+1)
	if l==0:
		print 2*k+2*p+2
	else:
		print 2*p+2+1+2*k+1
		
