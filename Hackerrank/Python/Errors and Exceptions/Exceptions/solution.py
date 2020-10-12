for _ in range(int(input())):
    try:
        a, b = (int(x) for x in input().split())
        print(a // b)
    except Exception as err:
        print("Error Code:", err)
