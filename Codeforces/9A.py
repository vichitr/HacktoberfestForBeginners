s = input()
y = s[0]
w = s[2]
if int(y) > int(w):
    p = 7 - int(y)
else:
    p = 7 - int(w)
if p == 1:
    print('1/6')
if p == 2:
    print('1/3')
if p == 3:
    print('1/2')
if p == 4:
    print('2/3')
if p == 5:
    print('5/6')
if p == 6:
    print('1/1')
