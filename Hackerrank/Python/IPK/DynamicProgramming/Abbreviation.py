def solve():
    a = input()
    b = input()
    n, m = len(a), len(b)

    dp = [[False] * (m + 1) for _ in range(n + 1)]

    dp[0][0] = True
    for i in range(1, n + 1):
        dp[i][0] = a[:i].islower()

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if a[i - 1].isupper():
                dp[i][j] = dp[i - 1][j - 1] if a[i - 1] == b[j - 1] else False
            else:
                if a[i - 1].upper() == b[j - 1]:
                    dp[i][j] = dp[i - 1][j] or dp[i - 1][j - 1]
                else:
                    dp[i][j] = dp[i - 1][j]

    return 'YES' if dp[n][m] else 'NO'


def main():
    queries = int(input())

    for _ in range(queries):
        print(solve())


if __name__ == '__main__':
    main()
