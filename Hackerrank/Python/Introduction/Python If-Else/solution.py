N = int(input())

if (N % 2 == 1) or (N in range(6, 21)):
    print("Weird")
else:
    print("Not Weird")
