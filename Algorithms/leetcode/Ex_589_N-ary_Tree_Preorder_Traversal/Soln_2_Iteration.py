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
        if not root:
            return li
        stack = [root]
        while stack:
            node = stack.pop()
            li.append(node.val)
            if node.children:
                # 先加入最右孩子，最后加入最左孩子
                stack.extend([node.children[i]
                              for i in range(len(node.children)-1, -1, -1)])
                # 展开list comprehension
                # for i in range(len(node.children)-1, -1, -1):
                #     stack.append(node.children[i])
        return li


# 与144题：二叉树先序遍历很像
