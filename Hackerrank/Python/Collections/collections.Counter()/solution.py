from collections import Counter

_ = input()
shoes = Counter([int(x) for x in input().split()])

profits = 0
num_customers = int(input())
for _ in range(num_customers):
    size, price = (int(x) for x in input().split())
    num_left = shoes[size]
    if num_left:
        profits += price
        shoes[size] = num_left - 1
print(profits)
