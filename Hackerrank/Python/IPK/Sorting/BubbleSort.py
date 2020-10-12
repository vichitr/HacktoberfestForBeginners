def main():
    n = int(input())
    a = list(map(int, input().split()))
    swaps = 0

    for _ in range(n):
        for j in range(n - 1):
            if a[j] > a[j + 1]:
                swaps += 1
                a[j], a[j + 1] = a[j + 1], a[j]

    print('\n'.join([
        f'Array is sorted in {swaps} swaps.',
        f'First Element: {a[0]}',
        f'Last Element: {a[-1]}'
    ]))


if __name__ == '__main__':
    main()
