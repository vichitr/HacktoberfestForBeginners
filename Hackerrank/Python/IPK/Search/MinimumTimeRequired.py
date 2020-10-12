def count(machines, days):
    return sum(map(lambda x: days // x, machines))


def main():
    n, goal = map(int, input().split())
    machines = list(map(int, input().split()))

    lower = 0
    upper = goal * min(machines)

    while lower < upper:
        middle = (lower + upper) // 2
        if count(machines, middle) >= goal:
            upper = middle
        else:
            lower = middle + 1

    print(lower)


if __name__ == '__main__':
    main()
