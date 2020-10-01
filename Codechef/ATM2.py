'''
Author: Nikhil Kaushal
Problem: ATM Machine | ATM2
Contest: September Mega Cook-Off 2018 Division 2 | COOK98B
'''


T = int(input())
j = 0
li = []
for i in range(T):
    N, K = input().split()
    N = int(N)
    K = int(K)
    nums = list(map(int, input().split()))
    for j in range(N):
        if 0 <= nums[j] <= K:
            K -= nums[j]
            li.append(1)
        else:
            li.append(0)
    string = "".join(str(e) for e in li)
    print(string)
    li.clear()
