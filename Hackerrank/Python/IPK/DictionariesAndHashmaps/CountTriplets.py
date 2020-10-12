from collections import defaultdict


def main():
    _, r = map(int, input().split())
    a = list(map(int, input().split()))
    r2 = r * r
    counter = defaultdict(int)
    counter2 = defaultdict(int)

    answer = 0

    for x in a:
        if r == 1:
            n = counter[x]
            answer += (n * (n - 1)) // 2
        else:
            if x % r == 0:
                counter2[x] += counter[x // r]
            if x % r2 == 0:
                answer += counter2[x // r]
        counter[x] += 1

    print(answer)


if __name__ == '__main__':
    main()
