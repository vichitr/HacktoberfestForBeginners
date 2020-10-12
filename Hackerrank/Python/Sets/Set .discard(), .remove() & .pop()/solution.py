_ = int(input())
numbers = {int(x) for x in input().split()}

num_commands = int(input())
for _ in range(num_commands):
    command = input().split() + ['']
    if command[0] == "pop":
        numbers.pop()
    elif command[0] == "discard":
        numbers.discard(int(command[1]))
    elif command[0] == "remove":
        numbers.remove(int(command[1]))

print(sum(numbers))
