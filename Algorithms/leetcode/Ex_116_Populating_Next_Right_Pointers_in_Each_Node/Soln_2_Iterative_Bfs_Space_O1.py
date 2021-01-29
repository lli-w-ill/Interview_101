"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

from collections import defaultdict


class Solution:
    def connect(self, root: 'Node') -> 'Node':
        prev = root
        while prev and prev.left:
            curr = prev
            while curr:
                curr.left.next = curr.right
                if curr.next:
                    # set右孩子的next节点
                    curr.right.next = curr.next.left
                curr = curr.next
            prev = prev.left
        return root

# Space: O(1)
