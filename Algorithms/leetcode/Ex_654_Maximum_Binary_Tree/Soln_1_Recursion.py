# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> TreeNode:
        if not nums:
            return None
        mmax, midx = max((v, i) for (i, v) in enumerate(nums))
        root = TreeNode(mmax)
        root.left = self.constructMaximumBinaryTree(nums[:midx])
        root.right = self.constructMaximumBinaryTree(nums[midx+1:])
        return root
