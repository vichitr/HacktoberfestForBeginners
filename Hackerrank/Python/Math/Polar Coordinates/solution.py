import cmath

c = complex(input())
r, phi = cmath.polar(c)
print(r, phi, sep='\n')
