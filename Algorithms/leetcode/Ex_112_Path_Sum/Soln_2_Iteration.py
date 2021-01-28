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

        stack = [(root, targetSum)]
        while stack:
            node, ts = stack.pop(0)
            if not node.left and not node.right and ts == node.val:
                return True
            if node.left:
                stack.append((node.left, ts - node.val))
            if node.right:
                stack.append((node.right, ts - node.val))
        return False
