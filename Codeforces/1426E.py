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

for _ in range(int(input()) if not True else 1):
    n = int(input())
    #n, k = map(int, input().split())
    a1, a2, a3 = map(int, input().split())
    b1, b2, b3 = map(int, input().split())
    #a = list(map(int, input().split()))
    #b = list(map(int, input().split()))
    #s = input()
    # r s p
    ans2 = min(a1, b2) + min(a2, b3) + min(a3, b1)
    p,q,r,s,t, u = a1,a2,a3,b1,b2,b3
    ans = 696969696969696
    from itertools import permutations
    for pp in permutations([1,2,3,4,5,6]):
        a1,a2,a3,b1,b2,b3 = p,q,r,s,t,u
        for i in pp:
            if i == 1:
                x = min(a1, b1)
                a1 -= x
                b1 -= x
            if i == 2:
                x = min(a1, b3)
                a1 -= x
                b3 -= x
            if i == 3:
                x = min(a2, b2)
                a1 -= x
                b2 -= x
            if i == 4:
                x = min(a2, b1)
                a2 -= x
                b1 -= x
            if i == 5:
                x = min(a3, b3)
                a3 -= x
                b3 -= x
            if i == 6:
                x = min(a3, b2)
                a3 -= x
                b2 -= x
        ans = min(ans, a1+a2+a3)
    print(ans, ans2)
 
