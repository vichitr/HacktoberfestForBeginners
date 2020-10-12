def main():
    _ = int(input())
    a = sorted(map(int, input().split()))

    print(min(map(lambda x: abs(x[0] - x[1]), zip(a, a[1:]))))


if __name__ == '__main__':
    main()
