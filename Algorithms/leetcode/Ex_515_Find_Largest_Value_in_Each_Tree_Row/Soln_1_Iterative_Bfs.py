# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def largestValues(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        levelMax = []
        queue = [root]
        while queue:
            size = len(queue)
            max = queue[0].val
            for i in range(size):
                node = queue.pop(0)
                if node.val > max:
                    max = node.val
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            levelMax.append(max)
        return levelMax
