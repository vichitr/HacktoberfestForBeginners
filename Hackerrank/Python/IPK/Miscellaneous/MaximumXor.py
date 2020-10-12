def binary(x):
    return f'{x:032b}'


class Node:
    def __init__(self):
        self.child = [None, None]


class Trie:
    def __init__(self):
        self.root = Node()

    def add(self, x):
        current = self.root
        for bit in map(int, binary(x)):
            if current.child[bit] is None:
                current.child[bit] = Node()
            current = current.child[bit]

    def max_xor(self, x):
        result = ''

        current = self.root
        for bit in map(int, binary(x)):
            inverted = bit ^ 1
            if current.child[inverted] is not None:
                result += '1'
                current = current.child[inverted]
            else:
                result += '0'
                current = current.child[bit]

        return int(result, 2)


def main():
    _ = int(input())
    xs = list(map(int, input().split()))

    trie = Trie()
    for x in xs:
        trie.add(x)

    m = int(input())
    for _ in range(m):
        x = int(input())
        print(trie.max_xor(x))


if __name__ == '__main__':
    main()
