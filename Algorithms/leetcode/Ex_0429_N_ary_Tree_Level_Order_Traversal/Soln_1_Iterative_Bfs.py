"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""


class Solution_1:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        if not root:
            return []
        queue = [root]
        levels = []
        while queue:
            size = len(queue)
            level = []
            for i in range(size):
                node = queue.pop(0)
                level.append(node.val)
                if node.children:
                    queue.extend(node.children)
            levels.append(level)
        return levels
