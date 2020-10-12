test_cases = int(input())
for _ in range(test_cases):
    _ = input()
    A = {int(x) for x in input().split()}
    _ = input()
    B = {int(x) for x in input().split()}
    print(A < B)
