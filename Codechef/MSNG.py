threshold = 10**12

def toDecimal(base,s):
	sum = 0
	l = 0
	# print(reversed(s))
	
	for ch in reversed(s):
		val = 0
		# print(ch,end='')
		if ch>='A' and ch<='Z':
			val = ord(ch) - 55
		else:
			val = ord(ch) - 48

		if val>=base:
			return -1

		sum = sum + val * (base**l)
		if sum > threshold:
			return -1
		l += 1
	return sum

t = int(input())
for z in range(t):
	n = int(input())
	table = []
	d = {}
	for i in range(n):
		base, s = input().split()
		# print(base , s)
		base = int(base)
		if base == -1:
			j = 2
			temp = []
			local = {}
			while j<=36:
				num = toDecimal(j,s)
				if num!=-1 and num not in local:
					local[num] = 1
					# temp.append(num)
					if num not in d:
						d[num] = 1
					else:
						d[num] += 1
				j+=1
			# table.append(temp)
		else:
			temp = []
			num = toDecimal(base,s)
			local = {}
			if num!=-1 and num not in local:
				local[num] = 1
				# temp.append(num)
				if num not in d:
					d[num] = 1
				else:
					d[num] += 1
			# table.append(temp)

	M = 10**14
	# for i in table:
	# 	for j in i:
	# 		ser = j
	# 		count = 0
	# 		for k in table:
	# 			for l in k:
	# 				if l == ser:
	# 					count+=1

	# 		if count == n:
	# 			if ser < M:
	# 				M = ser

	ans = -1
	for k in sorted(d.keys()):
		# print(k,d[k])
		if d[k] == n:
			ans = k
			break
	
	# if M <= threshold:
	# 	ans = M
	print(ans)