# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findBottomLeftValue(self, root: TreeNode) -> int:
        if not root:
            return 0
        parents = [root]
        while True:
            children = []
            for node in parents:
                if node.left:
                    children.append(node.left)
                if node.right:
                    children.append(node.right)
            if len(children) == 0:
                break
            else:
                parents = children
        return parents[0].val
