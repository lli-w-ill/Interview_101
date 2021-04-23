# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution_2:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if not root or not p or not q:
            return root
        if p.val > q.val:
            p, q = q, p
        return self.search(root, p, q)

    def search(self, node: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # base case
        if (node.val - p.val) * (node.val - q.val) <= 0:
            return node

        if node.val < p.val:
            return self.search(node.right, p, q)
        elif node.val > q.val:
            return self.search(node.left, p, q)


# 参考题解：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/solution/er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-3c/
