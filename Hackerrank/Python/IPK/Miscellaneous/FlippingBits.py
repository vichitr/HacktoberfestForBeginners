def flip(n):
    result = 0
    k = 1

    for _ in range(32):
        if n & 1 == 0:
            result += k

        k <<= 1
        n >>= 1

    return result


def main():
    queries = int(input())

    for _ in range(queries):
        n = int(input())
        print(flip(n))


if __name__ == '__main__':
    main()
