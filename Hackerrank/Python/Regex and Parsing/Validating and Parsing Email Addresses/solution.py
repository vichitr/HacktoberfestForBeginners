import re

REGEX = r"^<[a-zA-Z][\w\.-]*@[a-zA-Z]+\.[a-zA-Z]{1,3}>$"

for _ in range(int(input())):
    name, email = input().split()
    matches = re.match(REGEX, email)
    if matches:
        print(name, email)
