import re

line = input()
match = re.search(r'([a-zA-Z0-9])\1+', line)
print(match.group(1) if match else -1)
