def main():
    n = int(input())
    a = [0] * n
    for i in range(n):
        a[i] = int(input())

    candies = [1] * n

    for i in range(1, n):
        if a[i] > a[i - 1]:
            candies[i] = candies[i - 1] + 1

    for i in range(n - 2, -1, -1):
        if a[i] > a[i + 1] and candies[i] <= candies[i + 1]:
            candies[i] = candies[i + 1] + 1

    print(sum(candies))


if __name__ == '__main__':
    main()
