def main():
    n = int(input())
    k = int(input())
    a = [0] * n

    for i in range(n):
        a[i] = int(input())

    a.sort()

    ans = a[k - 1] - a[0]
    for i in range(1, n - k + 1):
        ans = min(ans, a[i + k - 1] - a[i])

    print(ans)


if __name__ == '__main__':
    main()
