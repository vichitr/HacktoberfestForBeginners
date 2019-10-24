import math
while True:

    try:
        mod = 1000000007
        t = int(input())
        while t:
            n,k = map(int,input().split())
            d = n - 1
            cnt = k - 1
            number = (cnt//d)
            a = cnt - d
            ans = 0
            ans = ans + cnt
            ap_sum = (number * ((2*a) - (number - 1)* d ))//2
            ans = ans + ap_sum
            final = ans % mod
            print(final)
            t -= 1
    except:
        break