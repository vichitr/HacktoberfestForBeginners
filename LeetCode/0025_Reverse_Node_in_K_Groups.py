class Node:
    def __init__(self, val=None):
        self.val = val
        self.next = None


class Solution:
    def __init__(self):
        self.head = None

    def reverseKGroup(self, head, k):
        cnt = 0
        c = 0
        curr = head
        next = None
        prev = None
        temp = curr
        while temp is not None and c < k:
            temp = temp.next
            c = c + 1
        print(c)
        if c == k:
            while (curr is not None and cnt < k):
                next = curr.next
                curr.next = prev
                prev = curr
                curr = next
                cnt = cnt + 1
            if next is not None:
                head.next = self.reverseKGroup(next, k)
            return prev
        else:
            return curr
