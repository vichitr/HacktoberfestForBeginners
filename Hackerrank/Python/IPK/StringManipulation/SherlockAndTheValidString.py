def count(s):
    frequencies = [0] * 26

    for letter in s:
        frequencies[ord(letter) - ord('a')] += 1

    return frequencies


def solve(s):
    frequencies = sorted(filter(lambda x: x > 0, count(s)))

    if len(set(frequencies)) > 2:
        return 'NO'

    if (frequencies[0] == frequencies[-1] or
            (frequencies[0] == 1 and frequencies[0] != frequencies[1]) or
            frequencies[1] - frequencies[0] == 1 or
            frequencies[-1] - frequencies[-2] == 1):
        return 'YES'

    return 'NO'


def main():
    s = input()
    print(solve(s))


if __name__ == '__main__':
    main()
