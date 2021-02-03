# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        if not root:
            return 0
        # 三种情况：
        # 第一种情况：最长路径穿过root节点
        # 第二种情况：最长路径在root的左子树
        # 第三种情况：最长路径在root的右子树
        leftSubtreeDiameter = self.diameterOfBinaryTree(root.left)
        rightSubtreeDiameter = self.diameterOfBinaryTree(root.right)
        passRootDiameter = self.dfs(root.left) + self.dfs(root.right)
        return max(leftSubtreeDiameter, rightSubtreeDiameter, passRootDiameter)

    def dfs(self, node: TreeNode) -> int:
        if not node:
            return 0   # 空节点
        if not node.left and not node.right:
            return 1   # 叶子结点
        return max(self.dfs(node.left), self.dfs(node.right)) + 1
