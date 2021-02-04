# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTilt(self, root: TreeNode) -> int:
        # 想法：先从root->leaves（top-down），然后叶子节点更新自己的val，自己的val
        # internal node同理，计算完左右子树绝对差后，保留以自己为根的子树的和，然后更新自己的val，返回给上一层子树的和，直至root
        if not root:
            return 0
        self.tilt = 0
        _ = self.dfs(root)
        return self.tilt

    def dfs(self, node: TreeNode) -> int:
        if not node:
            return 0
        # 先保存当前的值
        val = node.val
        # 左子树节点之和
        leftSum = self.dfs(node.left)
        # 右子树节点之和
        rightSum = self.dfs(node.right)
        node.val = abs(leftSum - rightSum)
        self.tilt += node.val
        return val + leftSum + rightSum
