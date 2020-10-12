import re

for _ in range(int(input())):
    line = input()
    if re.match(r"^[789]{1}\d{9}$", line):
        print("YES")
    else:
        print("NO")
