"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""


class Solution:
    def maxDepth(self, root: 'Node') -> int:
        if not root:
            return 0
        queue = [root]
        depth = 0
        while queue:
            size = len(queue)
            for i in range(size):
                node = queue.pop(0)
                for n in node.children:
                    queue.append(n)
            depth += 1
        return depth
