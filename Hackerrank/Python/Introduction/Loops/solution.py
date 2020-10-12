n = int(input())
squares = [x ** 2 for x in range(n)]
print(*squares, sep="\n")
