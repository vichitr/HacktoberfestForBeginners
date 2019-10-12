'''
    Problem Description:
    
        Given an n-ary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
'''

"""
# Definition for a Node.
class Node:
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
from collections import deque

class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        if root is None: return []
        q = deque()
        subq = deque()
        ans= []
        subans = []
        q.append(root)
        while len(q)!=0 :
            r = q.popleft()
            subans.append(r.val)
            for child in r.children:
                subq.append(child)
            if len(q)==0:
                ans.append(subans)
                subans = []
                q = subq
                subq = deque()
        return ans
