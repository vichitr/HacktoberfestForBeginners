DATA_MIN = -1
DATA_MAX = 10001


def is_bst(root):
    return check(root, DATA_MIN, DATA_MAX)


def check(root, left, right):
    if root is None:
        return True
    if root.data <= left or root.data >= right:
        return False
    return (check(root.left, left, root.data) and
            check(root.right, root.data, right))
