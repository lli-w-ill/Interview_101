# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        if not root:
            return []
        queue = [root]
        avg = []
        idx = 0
        while queue:
            size = len(queue)
            avg.append(0)
            for i in range(size):
                node = queue.pop(0)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
                avg[idx] += node.val
            avg[idx] /= size
            idx += 1
        return avg
