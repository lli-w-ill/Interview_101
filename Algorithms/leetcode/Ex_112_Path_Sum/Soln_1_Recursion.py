# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: TreeNode, targetSum: int) -> bool:
        # base cases
        if not root and targetSum == 0:
            return True
        if not root and targetSum != 0:
            return False
        if root and not root.left and not root.right:
            return root.val == targetSum

        if root.left:
            goLeft = self.hasPathSum(root.left, targetSum - root.val)
            if goLeft:
                return True
        if root.right:
            goRight = self.hasPathSum(root.right, targetSum - root.val)
            if goRight:
                return True
        return False
