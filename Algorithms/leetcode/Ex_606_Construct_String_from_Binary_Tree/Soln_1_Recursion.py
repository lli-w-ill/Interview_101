# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def tree2str(self, t: TreeNode) -> str:
        if not t:
            return ''
        s = ''
        s += self.toStr(t, '')
        return s

    def toStr(self, node: TreeNode, s: str) -> str:
        if not node.left and not node.right:
            return str(node.val)
        elif node.left and node.right:
            return str(node.val) + '(' + self.toStr(node.left, s) + ')' + '(' + self.toStr(node.right, s) + ')'
        elif node.left:
            # 右孩子为空可以省略不必要的空括号
            return str(node.val) + '(' + self.toStr(node.left, s) + ')'
        elif node.right:
            # 左孩子为空不能省略空括号
            return str(node.val) + '()' + '(' + self.toStr(node.right, s) + ')'
