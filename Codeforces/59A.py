def fancy(s):
	m,n=0,0
	for i in s:
		if i.isupper():
			m+=1
		else:
			n+=1
	if m>n:
		print(s.upper())
	else:
		print(s.lower())
s= input()
fancy(s)
