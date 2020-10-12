OPENING_CLOSING = {'(': ')', '[': ']', '{': '}'}


def is_balanced(brackets: str) -> bool:
    stack = []

    for bracket in brackets:
        if bracket in OPENING_CLOSING.keys():
            stack.append(bracket)
        elif len(stack) == 0 or OPENING_CLOSING[stack.pop()] != bracket:
            return False

    if len(stack) > 0:
        return False

    return True


def main():
    queries = int(input())

    for _ in range(queries):
        brackets = input()
        print('YES' if is_balanced(brackets) else 'NO')


if __name__ == '__main__':
    main()
