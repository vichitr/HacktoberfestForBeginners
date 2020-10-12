from bisect import bisect_left
from itertools import accumulate

MAX_LENGTH = 19
MAX_DECIMAL = 300000


def build_dp():
    """
    dp[i][j] - the number of decibinary numbers of length i which evaluates to
    decimal value j.
    """
    dp = [[0] * (MAX_DECIMAL + 1) for _ in range(MAX_LENGTH + 1)]
    dp[0][0] = 1
    exp = 1

    for length in range(1, MAX_LENGTH + 1):
        for decimal in range(0, MAX_DECIMAL + 1):
            for digit in range(10):
                prev = decimal - digit * exp
                if prev >= 0:
                    dp[length][decimal] += dp[length - 1][prev]
        exp <<= 1

    return dp


def build_prefix(dp):
    return list(accumulate(dp[MAX_LENGTH]))


def solve(dp, prefix, i):
    result = '0'
    decimal = bisect_left(prefix, i)
    j = i - (prefix[decimal - 1] if decimal > 0 else 0)

    exp = 1 << (MAX_LENGTH - 1)
    for length in range(MAX_LENGTH, 0, -1):
        digit = 0
        count = 0
        acc = dp[length - 1][decimal]

        while acc < j:
            digit += 1
            count = acc
            acc += dp[length - 1][decimal - digit * exp]

        result += str(digit)
        decimal -= digit * exp
        j -= count
        exp >>= 1

    return int(result)


def main():
    dp = build_dp()
    prefix = build_prefix(dp)

    q = int(input())
    for _ in range(q):
        i = int(input())
        print(solve(dp, prefix, i))


if __name__ == '__main__':
    main()
