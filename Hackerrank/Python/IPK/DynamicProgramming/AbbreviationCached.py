import functools
import sys

sys.setrecursionlimit(1000000)


@functools.lru_cache(maxsize=None)
def f(a: str, b: str) -> bool:
    if not b:
        return not a or a.islower()
    if not a:
        return False
    if a[-1].isupper():
        if a[-1] == b[-1]:
            return f(a[:-1], b[:-1])
        return False
    if a[-1].upper() == b[-1]:
        return f(a[:-1], b) or f(a[:-1], b[:-1])
    return f(a[:-1], b)


def solve():
    a = input()
    b = input()
    f.cache_clear()

    return 'YES' if f(a, b) else 'NO'


def main():
    queries = int(input())

    for _ in range(queries):
        print(solve())


if __name__ == '__main__':
    main()
