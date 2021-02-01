# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        return self.dfs(root, 0)

    def dfs(self, node: TreeNode, leftSum: int) -> int:
        if not node:
            return leftSum

        incre = 0
        if node.left:
            if not node.left.left and not node.left.right:
                incre += node.left.val
            else:
                incre += self.dfs(node.left, leftSum)
        if node.right:
            incre += self.dfs(node.right, leftSum)
        return leftSum + incre

# 注：
# 这个解法相较于解法2，减少了一个参数，每次计算增量，然后返回当前的leftSum加上增量后的结果
