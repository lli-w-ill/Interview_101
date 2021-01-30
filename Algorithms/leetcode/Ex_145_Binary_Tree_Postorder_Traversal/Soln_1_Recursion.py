# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        return self.postorder(root, [])

    def postorder(self, root: TreeNode, po: List[int]) -> List[int]:
        if not root:
            return po
        _ = self.postorder(root.left, po)
        _ = self.postorder(root.right, po)
        po.append(root.val)
        return po
