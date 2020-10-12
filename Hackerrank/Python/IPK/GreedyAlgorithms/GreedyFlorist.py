def main():
    n, k = map(int, input().split())
    prices = sorted(map(int, input().split()), reverse=True)
    answer = 0

    for i in range(0, n, k):
        answer += ((i // k) + 1) * sum(prices[i:i + k])

    print(answer)


if __name__ == '__main__':
    main()
