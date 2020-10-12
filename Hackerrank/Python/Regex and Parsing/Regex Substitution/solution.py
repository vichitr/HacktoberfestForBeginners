import re

REGEX = r'(?<= )(&&|\|\|)(?= )'
FIX_AND_OR = lambda x: 'and' if x.group() == '&&' else 'or'

for _ in range(int(input())):
    line = input()
    print(re.sub(REGEX, FIX_AND_OR, line))
