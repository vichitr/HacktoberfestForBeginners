n=int(raw_input())
a=map(int, raw_input().split())
if all(i<=25 for i in a):
	print '0'
else:
	print max(a)-25
