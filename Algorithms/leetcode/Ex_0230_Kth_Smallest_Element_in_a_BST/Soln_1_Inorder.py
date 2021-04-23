# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution_1:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        return self.inorder(root, k)[0].val

    def inorder(self, node: TreeNode, k: int) -> Tuple[TreeNode, int]:
        if node.left:
            left, k = self.inorder(node.left, k)
            if k == 0:
                return left, k
        k -= 1
        if k == 0:
            return node, k
        if node.right:
            right, k = self.inorder(node.right, k)
            if k == 0:
                return right, k
        return node, k
