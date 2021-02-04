"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""


class Solution:
    def maxDepth(self, root: 'Node') -> int:
        return self.dfs(root)

    def dfs(self, node: 'Node') -> int:
        if not node:
            return 0
        if not node.children:
            return 1
        return max([self.dfs(n) for n in node.children]) + 1
