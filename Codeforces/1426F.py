from bisect import bisect_left, bisect_right

class Result:
    def __init__(self, index, value):
        self.index = index
        self.value = value

class BinarySearch:
    def __init__(self):
        pass

    @staticmethod
    def greater_than(num: int, func, size: int = 1):
        """Searches for smallest element greater than num!"""
        if isinstance(func, list):
            index = bisect_right(func, num)
            if index == len(func):
                return Result(None, None)
            else:
                return Result(index, func[index])
        else:
            alpha, omega = 0, size - 1
            if func(omega) <= num:
                return Result(None, None)
            while alpha < omega:
                if func(alpha) > num:
                    return Result(alpha, func(alpha))
                if omega == alpha + 1:
                    return Result(omega, func(omega))
                mid = (alpha + omega) // 2
                if func(mid) > num:
                    omega = mid
                else:
                    alpha = mid

    @staticmethod
    def less_than(num: int, func, size: int = 1):
        """Searches for largest element less than num!"""
        if isinstance(func, list):
            index = bisect_left(func, num) - 1
            if index == -1:
                return Result(None, None)
            else:
                return Result(index, func[index])
        else:
            alpha, omega = 0, size - 1
            if func(alpha) >= num:
                return Result(None, None)
            while alpha < omega:
                if func(omega) < num:
                    return Result(omega, func(omega))
                if omega == alpha + 1:
                    return Result(alpha, func(alpha))
                mid = (alpha + omega) // 2
                if func(mid) < num:
                    alpha = mid
                else:
                    omega = mid

# ------------------- fast io --------------------
import os
import sys
from io import BytesIO, IOBase

BUFSIZE = 8192


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)


class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")

# ------------------- fast io --------------------
from math import gcd, ceil

def pre(s):
    n = len(s)
    pi = [0] * n
    for i in range(1, n):
        j = pi[i - 1]
        while j and s[i] != s[j]:
            j = pi[j - 1]
        if s[i] == s[j]:
            j += 1
        pi[i] = j
    return pi


def prod(a):
    ans = 1
    for each in a:
        ans = (ans * each)
    return ans

def lcm(a, b): return a * b // gcd(a, b)


def binary(x, length=16):
    y = bin(x)[2:]
    return y if len(y) >= length else "0" * (length - len(y)) + y

bs = BinarySearch()
for _ in range(int(input()) if not True else 1):
    n = int(input())
    s = input()
    mod = 10**9 + 7
    a = []
    b = []
    c = []
    q = []
    ans = 0
    for i in range(n):
        if s[i] == 'a': a+=[i]
        elif s[i] == 'b': b += [i]
        elif s[i] == 'c': c += [i]
        else: q += [i]

    q0 = pow(3, len(q), mod)
    q1 = pow(3, len(q)-1, mod) if len(q)>0 else 0
    q2 = pow(3, len(q)-2, mod) if len(q)>1 else 0
    q3 = pow(3, len(q)-3, mod) if len(q)>2 else 0

    # ab*
    # abc
    bc, bq = [], []
    for i in b:
        ind, ind2 = bs.greater_than(i, c).index, bs.greater_than(i, q).index
        count = 0 if ind is None else len(c)-ind
        count2 = 0 if ind2 is None else len(q)-ind2
        bc += [count]
        bq += [count2]
    for i in range(len(bc)-2, -1, -1):
        bc[i] += bc[i+1]
        bq[i] += bq[i+1]
    for i in a:
        ind = bs.greater_than(i, b).index
        if ind is None:continue
        if bc[ind]:
            ans += bc[ind] * q0
            ans = ans % mod
        if bq[ind]:
            ans += bq[ind] * q1
            ans = ans % mod
    # *bc
    # *b*
    for i in q:
        ind = bs.greater_than(i, b).index
        if ind is None:continue
        if bc[ind]:
            ans += bc[ind] * q1
            ans = ans % mod
        if bq[ind]:
            ans += bq[ind] * q2
            ans = ans % mod
    #a*c
    #a**
    bc, bq = [], []
    for i in q:
        ind, ind2 = bs.greater_than(i, c).index, bs.greater_than(i, q).index
        count = 0 if ind is None else len(c) - ind
        count2 = 0 if ind2 is None else len(q) - ind2
        bc += [count]
        bq += [count2]
    for i in range(len(bc) - 2, -1, -1):
        bc[i] += bc[i + 1]
        bq[i] += bq[i + 1]
    for i in a:
        ind = bs.greater_than(i, q).index
        if ind is None:continue
        if bc[ind]:
            ans += bc[ind] * q1
            ans = ans % mod
        if bq[ind]:
            ans += bq[ind] * q2
            ans = ans % mod

    # **c
    # ***
    for i in q:
        ind = bs.greater_than(i, q).index
        if ind is None: continue
        if bc[ind]:
            ans += bc[ind] * q2
            ans = ans % mod
        if bq[ind]:
            ans += bq[ind] * q3
            ans = ans % mod

    print(ans)
