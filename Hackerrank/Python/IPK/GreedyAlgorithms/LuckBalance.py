def main():
    n, k = map(int, input().split())
    acc = 0
    lucks = []

    for _ in range(n):
        luck, important = map(int, input().split())
        if not important:
            acc += luck
        else:
            lucks.append(luck)

    lucks.sort()

    if k == 0:
        print(acc - sum(lucks))
    else:
        print(acc + sum(lucks[-k:]) - sum(lucks[:-k]))


if __name__ == '__main__':
    main()
