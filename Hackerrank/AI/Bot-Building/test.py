def compatible(a, b):
	count = 0
	for i in range(len(b)):
		if a[i] == b[i]:
			h = 10
		elif abs(ord(a[i])-ord(b[i])) == 1:
			count += 1
			check = True
		else:
			count += 1
	if count == 1:
		return True
	else:
		return False

s = int(input())
n = int(input())
name = []
count = 0
for i in range(n):
	name.append(input())
for i in range(len(name)):
	for j in range(i + 1, len(name)):
		if compatible(name[i], name[j]):
			count += 1
print(count)
