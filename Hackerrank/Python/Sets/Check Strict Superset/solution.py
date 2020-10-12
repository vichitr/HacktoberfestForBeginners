A = {int(x) for x in input().split()}

is_A_superset = True
test_cases = int(input())
for _ in range(test_cases):
    B = {int(x) for x in input().split()}
    is_A_superset = A > B
    if not is_A_superset:
        break
print(is_A_superset)
