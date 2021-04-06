# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution_2:
    def isSymmetric(self, root: TreeNode) -> bool:
        if root is None:
            return True
        queue_left = [root.left]
        queue_right = [root.right]
        while queue_left and queue_right:
            left = queue_left.pop()
            right = queue_right.pop()
            if left == right == None:
                continue
            if left is None or right is None:
                return False
            if left.val != right.val:
                return False
            queue_left.extend([left.left, left.right])
            queue_right.extend([right.right, right.left])
        return True
