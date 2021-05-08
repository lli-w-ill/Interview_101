"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""


class Solution_2:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        return self.dfs(root, 0, [])

    def dfs(self, node: 'Node', depth: int, levels: List[List[int]]) -> List[List[int]]:
        if not node:
            return levels
        if depth == len(levels):
            levels.append([node.val])
        else:
            levels[depth].append(node.val)
        if node.children:
            for child in node.children:
                self.dfs(child, depth+1, levels)
        return levels
