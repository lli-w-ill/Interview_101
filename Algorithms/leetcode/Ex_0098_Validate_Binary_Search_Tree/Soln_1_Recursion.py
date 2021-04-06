# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution_1:
    def isValidBST(self, root: TreeNode) -> bool:
        if root is None:
            return True
        return self.verify(root.left, -2**31, root.val - 1) and \
            self.verify(root.right, root.val + 1, 2**31-1)

    def verify(self, node: TreeNode, minVal: int, maxVal: int) -> bool:
        if node is None:
            return True
        if minVal > maxVal:
            return False
        if node.val < minVal or node.val > maxVal:
            return False
        return self.verify(node.left, minVal, min(node.val - 1, maxVal)) and \
            self.verify(node.right, node.val + 1, maxVal)
