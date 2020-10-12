import re

S, k = input(), input()
pattern = re.compile(k)

matches = pattern.search(S)
if not matches:
    print("(-1, -1)")
while matches:
    print("({}, {})".format(matches.start(), matches.end() - 1))
    matches = pattern.search(S, matches.start() + 1)
