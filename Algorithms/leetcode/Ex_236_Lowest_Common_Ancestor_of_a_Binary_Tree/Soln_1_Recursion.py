# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if not root or not p or not q:
            return None
        if root == p or root == q:
            return root
        leftCommon = self.lowestCommonAncestor(root.left, p, q)
        rightCommon = self.lowestCommonAncestor(root.right, p, q)
        # print(root.val, leftCommon, rightCommon)
        if leftCommon and rightCommon:
            return root
        if not leftCommon:
            return rightCommon
        if not rightCommon:
            return leftCommon

# 参考：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/solution/er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-3c/
