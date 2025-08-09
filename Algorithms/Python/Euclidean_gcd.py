def gcd(a,b): 
    while b:
        a, b = b, a % b
    return a
a,b=map(int,input().split())
print("gcd of a and b is = ",gcd(a,b))
