# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution_1:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        return self.preorder(root, [])

    def preorder(self, node: TreeNode, po: List[int]) -> List[int]:
        if not node:
            return po
        po.append(node.val)
        _ = self.preorder(node.left, po)
        _ = self.preorder(node.right, po)
        return po
