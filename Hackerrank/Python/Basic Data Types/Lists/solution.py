def parse_and_execute(result_list, command, args):
    """Parses commands and executes them on the given list."""
    if command != "print":
        eval("result_list." + command + "(" + ", ".join(args) + ")")
    else:
        print(result_list)

result_list = []
num_commands = int(input())
for _ in range(num_commands):
    command = input().split(' ')
    parse_and_execute(result_list, command[0], command[1:])
