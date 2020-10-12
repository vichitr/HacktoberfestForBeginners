from math import sqrt


def is_prime(n):
    if n == 1:
        return False
    if n == 2:
        return True

    i = 2
    while i <= sqrt(n):
        if n % i == 0:
            return False
        i += 1

    return True


def main():
    p = int(input())

    for _ in range(p):
        n = int(input())
        print('Prime' if is_prime(n) else 'Not prime')


if __name__ == '__main__':
    main()
