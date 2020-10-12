_ = int(input())
numbers = {int(x) for x in input().split()}

num_commands = int(input())
for _ in range(num_commands):
    command = input().split()[0]
    other_numbers = {int(x) for x in input().split()}
    if command == "update":
        numbers |= other_numbers
    elif command == "intersection_update":
        numbers &= other_numbers
    elif command == "difference_update":
        numbers -= other_numbers
    elif command == "symmetric_difference_update":
        numbers ^= other_numbers
print(sum(numbers))
