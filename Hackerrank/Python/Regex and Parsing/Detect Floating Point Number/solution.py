import re

for _ in range(int(input())):
    line = input()
    line_is_float = bool(re.match(r'^[+-]?\d*\.\d+$', line))
    print(line_is_float)
