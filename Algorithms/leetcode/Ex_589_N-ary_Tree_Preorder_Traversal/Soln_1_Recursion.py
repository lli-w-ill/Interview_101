"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""


class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        li = []
        self.traverse(root, li)
        return li

    def traverse(self, node: 'Node', li: List[int]) -> None:
        if not node:
            return
        li.append(node.val)
        for child in node.children:
            self.traverse(child, li)
