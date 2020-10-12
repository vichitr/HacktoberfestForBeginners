class Node:
    def __init__(self, key, parent=None):
        self.key = key
        self.parent = parent
        self.left = None
        self.right = None
        self.height = 1

    def insert(self, node):
        current = self

        while True:
            if node.key < current.key:
                if current.left is None:
                    node.parent = current
                    current.left = node
                    break
                else:
                    current = current.left
            else:
                if current.right is None:
                    node.parent = current
                    current.right = node
                    break
                else:
                    current = current.right

    def min(self):
        current = self
        while current.left is not None:
            current = current.left
        return current

    def next_larger(self):
        if self.right is not None:
            return self.right.min()

        current = self
        while current.parent is not None and current is current.parent.right:
            current = current.parent
        return current.parent


class Tree:
    def __init__(self):
        self.root = None

    def insert(self, key):
        node = Node(key)

        if self.root is None:
            self.root = node
        else:
            self.root.insert(node)
            self.rebalance(node.parent)

        return node

    def left_rotate(self, x):
        y = x.right
        y.parent = x.parent
        if y.parent is None:
            self.root = y
        else:
            if y.parent.left is x:
                y.parent.left = y
            elif y.parent.right is x:
                y.parent.right = y
        x.right = y.left
        if x.right is not None:
            x.right.parent = x
        y.left = x
        x.parent = y
        update_height(x)
        update_height(y)

    def right_rotate(self, x):
        y = x.left
        y.parent = x.parent
        if y.parent is None:
            self.root = y
        else:
            if y.parent.left is x:
                y.parent.left = y
            elif y.parent.right is x:
                y.parent.right = y
        x.left = y.right
        if x.left is not None:
            x.left.parent = x
        y.right = x
        x.parent = y
        update_height(x)
        update_height(y)

    def rebalance(self, node):
        while node is not None:
            update_height(node)
            left_height = get_height(node.left)
            right_height = get_height(node.right)
            if get_height(node.left) == right_height:
                break
            elif left_height - get_height(node.right) > 1:
                if get_height(node.left.left) >= get_height(node.left.right):
                    self.right_rotate(node)
                else:
                    self.left_rotate(node.left)
                    self.right_rotate(node)
            elif right_height - left_height > 1:
                if get_height(node.right.right) >= get_height(node.right.left):
                    self.left_rotate(node)
                else:
                    self.right_rotate(node.right)
                    self.left_rotate(node)
            node = node.parent


def get_height(node):
    return node.height if node is not None else 0


def update_height(node):
    node.height = max(get_height(node.left), get_height(node.right)) + 1


def solve(n, m, a):
    current = 0
    result = 0
    memory = Tree()

    for i in range(n):
        current = (current + a[i]) % m
        result = max(result, current)

        node = memory.insert(current)
        next_larger = node.next_larger()
        if next_larger is not None:
            result = max(result, (current - next_larger.key + m) % m)

    return result


def main():
    qs = int(input())
    answer = [0] * qs

    for q in range(qs):
        n, m = map(int, input().split())
        a = list(map(int, input().split()))
        answer[q] = solve(n, m, a)

    print('\n'.join(map(str, answer)))


if __name__ == '__main__':
    main()
