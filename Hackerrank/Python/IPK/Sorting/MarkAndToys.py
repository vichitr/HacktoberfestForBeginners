def main():
    _, money = map(int, input().split())
    prices = sorted(map(int, input().split()))
    answer = 0

    for price in prices:
        if price > money:
            break
        money -= price
        answer += 1

    print(answer)


if __name__ == '__main__':
    main()
