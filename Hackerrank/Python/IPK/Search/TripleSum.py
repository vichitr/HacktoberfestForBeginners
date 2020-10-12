def main():
    _ = input()
    xs = sorted(set(map(int, input().split())))
    ys = sorted(set(map(int, input().split())))
    zs = sorted(set(map(int, input().split())))
    count = 0

    i = 0
    j = 0

    for y in ys:
        while i < len(xs) and xs[i] <= y:
            i += 1
        while j < len(zs) and zs[j] <= y:
            j += 1

        count += i * j

    print(count)


if __name__ == '__main__':
    main()
