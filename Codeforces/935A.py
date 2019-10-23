inp = int(input())
output = 0
for x in range(1, int(inp/2) + 1):
    s = str((inp-x)/x)
    if s[-1] == '0' and s[-2] == '.':
        output += 1
print(output)
