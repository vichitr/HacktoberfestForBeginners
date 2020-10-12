import math

AB = int(input())
BC = int(input())

AC = math.sqrt(AB**2 + BC**2)
MBC = round(math.degrees(math.acos(BC/AC)))
print(MBC, chr(176), sep='')
