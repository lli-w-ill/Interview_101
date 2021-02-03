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
        bottomLevel = [root]
        leftmost = self.bfs(bottomLevel, None)
        return leftmost.val

    def bfs(self, parents: List[TreeNode], leftmost: TreeNode) -> TreeNode:
        if len(parents) == 0:
            return leftmost
            return
        size = len(parents)
        leftmost = parents[0]
        for i in range(size):
            node = parents.pop(0)
            if node.left:
                parents.append(node.left)
            if node.right:
                parents.append(node.right)
        return self.bfs(parents, leftmost)
