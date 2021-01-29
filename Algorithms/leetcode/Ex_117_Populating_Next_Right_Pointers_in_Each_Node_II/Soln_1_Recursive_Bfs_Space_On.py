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
        if not root:
            return None
        nodes = defaultdict(list)
        self.bfs(root, 1, nodes)
        for depth in nodes.keys():
            for i in range(len(nodes[depth])-1):
                nodes[depth][i].next = nodes[depth][i+1]
            nodes[depth][-1].next = None
        return nodes[1][0]

    def bfs(self, node: 'Node', depth: int, nodes: Dict[int, 'Node']) -> None:
        if not node:
            return
        nodes[depth].append(node)
        self.bfs(node.left, depth+1, nodes)
        self.bfs(node.right, depth+1, nodes)
