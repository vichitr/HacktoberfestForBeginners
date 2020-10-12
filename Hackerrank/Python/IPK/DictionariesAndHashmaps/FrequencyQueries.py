from collections import defaultdict


def main():
    qs = int(input())
    freq = defaultdict(int)
    counter = defaultdict(int)
    answers = []

    for _ in range(qs):
        q, x = map(int, input().split())
        if q == 1:
            counter[freq[x]] = max(0, counter[freq[x]] - 1)
            freq[x] += 1
            counter[freq[x]] += 1
        if q == 2:
            counter[freq[x]] = max(0, counter[freq[x]] - 1)
            freq[x] = max(0, freq[x] - 1)
            counter[freq[x]] += 1
        if q == 3:
            answers.append(int(counter[x] > 0))

    print('\n'.join(map(str, answers)))


if __name__ == '__main__':
    main()
