def is_leaf(node):
    return node.left is None and node.right is None


def decode(root, s):
    result = ''

    current = root
    for bit in s:
        if bit == '0':
            current = current.left
        else:
            current = current.right

        if is_leaf(current):
            result += current.data
            current = root

    print(result)
