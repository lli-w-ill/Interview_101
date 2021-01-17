# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        return self.dfs(p, q)

    def dfs(self, p: TreeNode, q: TreeNode) -> bool:
        if p and q:
            if p.val == q.val:
                return self.dfs(p.left, q.left) and self.dfs(p.right, q.right)
            else:
                return False
        if p or q:
            return False
        return True
