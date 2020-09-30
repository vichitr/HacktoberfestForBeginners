string = input()
string = list(string.split(' '))
a,b,c = int(string[0]), int(string[1]), int(string[2])
a, b = b, a
a *= c
b += c
print(a,b)
