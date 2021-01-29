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
        if root:
            left = root.left
            right = root.right
            while left:
                left.next = right
                left = left.right
                right = right.left
            self.connect(root.left)
            self.connect(root.right)
        return root


# Space: O(1)
# 参考：https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/solution/la-la-lian-jie-fa-by-sorcerer/
# 参考：https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/solution/dong-hua-yan-shi-san-chong-shi-xian-116-tian-chong/
