
from collections import Counter 
n=int(input())
s=list(input())
m=Counter(s)
print(m.most_common(1)[0][1])
