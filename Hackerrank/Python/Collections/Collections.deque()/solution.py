"""
We could also use eval() to directly call the given methods.
"""

from collections import deque

numbers = deque()
for _ in range(int(input())):
    method_args = input().split()
    if method_args[0] == "append":
        numbers.append(method_args[1])
    if method_args[0] == "appendleft":
        numbers.appendleft(method_args[1])
    if method_args[0] == "pop":
        numbers.pop()
    if method_args[0] == "popleft":
        numbers.popleft()
print(*numbers)
