# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution_3:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if not root:
            return root
        queue = [root]
        while queue:
            node = queue.pop()
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
            node.left, node.right = node.right, node.left
        return root
