import re

for _ in range(int(input())):
    try:
        re.compile(input())
    except:
        print("False")
    else:
        print("True")