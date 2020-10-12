import math


def main():
    m, w, p, n = map(int, input().split())
    answer = math.ceil(n / (m * w))

    candies = 0
    passed = 0

    while True:
        left = math.ceil((n - candies) / (m * w))
        answer = min(answer, passed + left)

        if left <= 1:
            break

        if candies < p:
            required = math.ceil((p - candies) / (m * w))
            passed += required
            candies += required * m * w

        if m < w:
            m += 1
        else:
            w += 1
        candies -= p

    print(answer)


if __name__ == '__main__':
    main()
