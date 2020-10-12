from collections import defaultdict

A_indices = defaultdict(list)
n, m = (int(x) for x in input().split())

# Map each string in A to a list of indices where it occurs
for i in range(1, n+1):
    A_indices[input()].append(str(i))

# Print the list of indices in A (or -1) for each string in B
for i in range(m):
    b = input()
    if b in A_indices:
        print(*A_indices[b])
    else:
        print(-1)
