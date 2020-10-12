def main():
    n = int(input())
    s = input() + '.'

    answer = 0

    current = 1
    for i in range(n):
        if s[i] != s[i + 1]:
            answer += current * (current + 1) // 2
            current = 1
        else:
            current += 1

    left = [1] * n
    left[0] = 0
    right = [1] * n
    right[-1] = 0

    for i in range(2, n):
        if s[i - 1] == s[i - 2]:
            left[i] = left[i - 1] + 1
        if s[n - i + 1] == s[n - i]:
            right[n - i - 1] = right[n - i] + 1

    for i in range(1, n - 1):
        if s[i] != s[i - 1] and s[i - 1] == s[i + 1]:
            answer += min(left[i], right[i])

    print(answer)


if __name__ == '__main__':
    main()
