import sys

sys.setrecursionlimit(1000000)


def super_digit(n):
    while n > 9:
        n = sum(map(int, str(n)))
    return n


def main():
    n, k = map(int, input().split())
    print(super_digit(super_digit(n) * k))


if __name__ == '__main__':
    main()
