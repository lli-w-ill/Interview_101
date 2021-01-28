# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: TreeNode, targetSum: int) -> List[List[int]]:
        ans = []
        stack = [(root, targetSum, [])]
        while stack:
            node, ts, li = stack.pop(0)
            if not node:
                break
            if not node.left and not node.right and node.val == ts:
                ans.append(li + [node.val])

            if node.left:
                stack.append((node.left, ts - node.val, li + [node.val]))
            if node.right:
                stack.append((node.right, ts - node.val, li + [node.val]))
        return ans
