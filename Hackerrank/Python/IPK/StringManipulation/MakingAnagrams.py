def count(s):
    counts = [0] * 26

    for letter in s:
        counts[ord(letter) - ord('a')] += 1

    return counts


def diff(xs, ys):
    return sum(abs(x - y) for (x, y) in zip(xs, ys))


def main():
    a = input()
    b = input()
    print(diff(count(a), count(b)))


if __name__ == '__main__':
    main()
