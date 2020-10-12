def main():
    n = int(input())
    heights = list(map(int, input().split()))
    heights.append(0)
    answer = 0
    stack = [(heights[0], 0)]

    for i in range(1, n + 1):
        left = i

        if heights[i] < stack[-1][0]:
            while stack and stack[-1][0] >= heights[i]:
                top = stack.pop()
                left = top[1]
                answer = max(answer, top[0] * (i - left))

        stack.append((heights[i], left))

    print(answer)


if __name__ == '__main__':
    main()
