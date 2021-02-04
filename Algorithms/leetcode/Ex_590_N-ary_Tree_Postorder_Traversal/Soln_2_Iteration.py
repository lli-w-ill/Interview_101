"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""


class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        li = []
        if not root:
            return li
        stack = [root]
        while stack:
            node = stack.pop()
            li.append(node.val)
            if node.children:
                stack.extend(node.children)
        # li中存储的顺序是：中，右，左
        # 后续遍历的顺序是：左，右，中
        # 所以只需要返回逆序即可
        return li[::-1]


# 与145题：二叉树的后序遍历很像
