# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution_3:
    def isValidBST(self, root: TreeNode) -> bool:
        self.nums = []
        self.inorder(root)
        for i in range(1, len(self.nums)):
            if self.nums[i] <= self.nums[i-1]:
                return False
        return True

    def inorder(self, node: TreeNode) -> None:
        if node is None:
            return
        self.inorder(node.left)
        self.nums.append(node.val)
        self.inorder(node.right)
