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
        if not root or (not root.left and not root.right):
            return root
        if root.left and root.right:
            root.left.next = root.right
            root.right.next = self.getNextNonNullNode(root)
        elif root.left:
            root.left.next = self.getNextNonNullNode(root)
        elif root.right:
            root.right.next = self.getNextNonNullNode(root)
        # 首先递归右子树
        self.connect(root.right)
        self.connect(root.left)
        return root

    def getNextNonNullNode(self, parent: 'Node') -> 'Node':
        while parent.next:
            if parent.next.left:
                return parent.next.left
            if parent.next.right:
                return parent.next.right
            parent = parent.next
        return None

# 参考：https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/solution/di-gui-fa-jian-dan-yi-dong-ban-xin-shou-kan-by-lov/
