from bisect import bisect_left


def main():
    n, k = map(int, input().split())
    a = sorted(map(int, input().split()))
    count = 0

    for i in range(n):
        x = a[i] + k
        position = bisect_left(a, x, i + 1)
        while position < n and a[position] == x:
            count += 1
            position += 1

    print(count)


if __name__ == '__main__':
    main()
