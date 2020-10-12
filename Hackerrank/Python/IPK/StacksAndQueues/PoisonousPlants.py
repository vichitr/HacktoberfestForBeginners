def main():
    _ = int(input())
    plants = list(map(int, input().split()))
    plants.append(-1)
    answer = 0

    stack = []
    for i, plant in enumerate(plants):
        days = 1
        while stack and stack[-1][0] >= plant:
            days = max(days, stack[-1][1] + 1)
            stack.pop()

        if not stack:
            days = -1

        answer = max(answer, days)
        stack.append((plant, days))

    print(answer)


if __name__ == '__main__':
    main()
