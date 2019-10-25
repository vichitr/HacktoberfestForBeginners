p_in = input()
s_in = input()
p = 0
for x in range(int(p_in)*2 - 1):
    if s_in[x] == '1':
        p = 1
if p == 1:
    print("Hard")
else:
    print("Easy")
