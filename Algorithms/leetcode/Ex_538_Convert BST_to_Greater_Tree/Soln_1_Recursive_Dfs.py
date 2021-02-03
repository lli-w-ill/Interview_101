# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def convertBST(self, root: TreeNode) -> TreeNode:
        # 根据示例1，可知访问顺序应该是：右->中->左
        _ = self.dfs(root, 0)
        return root

    def dfs(self, node: TreeNode, sum: int) -> int:
        if not node:
            return sum
        # 右
        sum = self.dfs(node.right, sum)
        # 中
        node.val += sum
        # 左
        sum = self.dfs(node.left, node.val)
        return sum
