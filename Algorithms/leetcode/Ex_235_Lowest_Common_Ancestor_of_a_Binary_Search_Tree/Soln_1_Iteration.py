# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if not root:
            return root
        # 保证p的值永远比q要小
        if p.val > q.val:
            p, q = q, p
        while root != p or root != q:
            if root.val >= p.val and root.val <= q.val:
                break
            elif root.val < p.val:
                root = root.right
            elif root.val > q.val:
                root = root.left
        return root
