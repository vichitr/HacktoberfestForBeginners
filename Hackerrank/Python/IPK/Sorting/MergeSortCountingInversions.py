def sort(a, left, right):
    swaps = 0
    if right - left == 1:
        return swaps

    middle = left + ((right - left) // 2)

    swaps += sort(a, left, middle)
    swaps += sort(a, middle, right)
    swaps += merge(a, left, middle, right)

    return swaps


def merge(a, left, middle, right):
    swaps = 0

    buffer = [0] * (right - left)
    current = 0
    i, j = left, middle

    while i < middle and j < right:
        if a[i] > a[j]:
            buffer[current] = a[j]
            j += 1
            swaps += middle - i
        else:
            buffer[current] = a[i]
            i += 1
        current += 1

    while i < middle:
        buffer[current] = a[i]
        i += 1
        current += 1

    while j < right:
        buffer[current] = a[j]
        j += 1
        current += 1

    a[left:right] = buffer

    return swaps


def solve():
    n = int(input())
    a = list(map(int, input().split()))

    return sort(a, 0, n)


def main():
    d = int(input())

    for _ in range(d):
        print(solve())


if __name__ == '__main__':
    main()
