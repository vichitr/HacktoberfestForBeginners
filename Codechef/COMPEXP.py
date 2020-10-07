T = int(raw_input())

while T > 0:
	S = raw_input().split()
	N = int(S[0])
	K = int(S[1])
	ans = 2 * (N - (N - 1) * 1.0/(K * 1.0));
	print("%.9f" % ans)
	T = T - 1
