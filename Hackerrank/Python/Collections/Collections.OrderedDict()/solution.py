from collections import OrderedDict

items_sold = OrderedDict()
for _ in range(int(input())):
    item, _, price = input().rpartition(' ')
    price = int(price)
    if item in items_sold:
        items_sold[item] += price
    else:
        items_sold[item] = price

for item, price in items_sold.items():
    print(item, price)
