# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        if not root:
            return True
        lh = self.getHeight(root.left)
        lr = self.getHeight(root.right)
        return abs(lh - lr) <= 1 and self.isBalanced(root.left) and self.isBalanced(root.right)

    def getHeight(self, node: TreeNode) -> int:
        if node is None:
            return 0
        else:
            return max(self.getHeight(node.left), self.getHeight(node.right)) + 1
