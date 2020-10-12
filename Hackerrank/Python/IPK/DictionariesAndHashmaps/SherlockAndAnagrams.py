def count(s):
    result = 0
    n = len(s)

    for length in range(1, n):
        for i in range(n - length):
            substring = sorted(s[i:i + length])
            for j in range(i + 1, n):
                if substring == sorted(s[j:j + length]):
                    result += 1

    return result


def main():
    queries = int(input())
    answers = [0] * queries

    for query in range(queries):
        s = input()
        answers[query] = count(s)

    print('\n'.join(map(str, answers)))


if __name__ == '__main__':
    main()
