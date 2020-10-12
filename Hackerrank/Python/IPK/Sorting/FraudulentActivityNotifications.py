N = 201


def count(xs):
    counts = [0] * N
    for x in xs:
        counts[x] += 1
    return counts


def find_doubled_median(d, counts):
    middle = d // 2 + (d % 2)
    cnt = 0
    i = 0

    while cnt + counts[i] < middle:
        cnt += counts[i]
        i += 1

    if d % 2 == 1:
        return 2 * i

    j = i
    while cnt + counts[j] < middle + 1:
        cnt += counts[j]
        j += 1

    return i + j


def main():
    n, d = map(int, input().split())
    expenditures = list(map(int, input().split()))
    notifications = 0

    counts = count(expenditures[:d])

    for i, expenditure in enumerate(expenditures[d:]):
        if expenditure >= find_doubled_median(d, counts):
            notifications += 1
        counts[expenditure] += 1
        counts[expenditures[i]] -= 1

    print(notifications)


if __name__ == '__main__':
    main()
