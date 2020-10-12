def solve():
    s = input()
    answer = 0

    for i in range(1, len(s)):
        answer += s[i] == s[i - 1]

    return answer


def main():
    q = int(input())

    for _ in range(q):
        print(solve())


if __name__ == '__main__':
    main()
