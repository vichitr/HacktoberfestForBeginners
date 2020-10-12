import re

REGEX = r'[\s:](#[a-f\d]{3,6})'

for _ in range(int(input())):
    line = input()
    matches = re.findall(REGEX, line, re.IGNORECASE)
    if matches:
        print("\n".join(matches))
