# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution_2:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        leftSum = [0]
        self.dfs(root, leftSum)
        return leftSum[0]

    def dfs(self, node: TreeNode, leftSum: List[int]) -> None:
        if not node:
            return leftSum

        if node.left:
            if not node.left.left and not node.left.right:
                leftSum[0] += node.left.val
            else:
                self.dfs(node.left, leftSum)
        if node.right:
            self.dfs(node.right, leftSum)

# 注：
# leftSum作为参数传进去，并随着dfs随时修改；
# 这个解法等同于用全局变量
