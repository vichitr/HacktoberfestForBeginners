"""
This solution uses extra space in the form of two deques,
in order to maintain the actual stacking order. This was
not required by the problem statement.
"""

from collections import deque

for _ in range(int(input())):
    _ = input()
    cubes = deque([int(x) for x in input().split()])
    cube_stack = deque()
    cube_stack.append(float('inf'))
    while cubes:
        larger_cube = (cubes.popleft()
            if cubes[0] > cubes[-1] else cubes.pop())
        if larger_cube <= cube_stack[-1]:
            cube_stack.append(larger_cube)
        else:
            print("No")
            break
    else:
        print("Yes")
