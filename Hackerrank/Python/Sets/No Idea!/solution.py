"""Why is this challenge called 'No Idea!'? I have no idea."""

_ = input()
numbers = [int(x) for x in input().split()]
A = {int(x) for x in input().split()}
B = {int(x) for x in input().split()}

happiness = 0
for number in numbers:
    if number in A:
        happiness += 1
    elif number in B:
        happiness -= 1

print(happiness)
