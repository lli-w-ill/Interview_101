# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution_2:
    def sumNumbers(self, root: TreeNode) -> int:
        ssum = 0
        stack = [(root, 0)]
        while stack:
            node, num = stack.pop(0)
            if not node:
                return num
            if node.left:
                stack.append((node.left, num * 10 + node.val))
            if node.right:
                stack.append((node.right, num * 10 + node.val))
            if not node.left and not node.right:
                ssum += num * 10 + node.val
        return ssum
