"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

import itertools


class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        if not root:
            return []
        return self.bfs([root], [])

    def bfs(self, currLevel: List['Node'], levels: List[List[int]]) -> List[List[int]]:
        if not currLevel:
            return levels
        # 将本层的所有节点存入levels
        levels.append([node.val for node in currLevel])
        # 将currLevel置为本层所有节点的children，并用itertools将children lists合并成一个list
        currLevel = list(itertools.chain.from_iterable(
            parent.children for parent in currLevel))
        return self.bfs(currLevel, levels)
