M=10**9+7
n=input()
a=map(int,raw_input().split())
if a[0]%2==0 or a[-1]%2==0:
	print "No"
elif n%2==1 and a[0]%2==1 and a[-1]%2==1:
	print "Yes"
elif n%2==0 and a[0]%2==1 and a[-1]%2==1:
	print "No"
else:
	print "Yes"
