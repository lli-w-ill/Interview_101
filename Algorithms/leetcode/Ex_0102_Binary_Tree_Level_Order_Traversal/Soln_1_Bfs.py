# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution_1:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return []
        currLevel = [root]
        levelOrder = [[root.val]]
        while currLevel:
            nextLevel = []
            while currLevel:
                node = currLevel.pop(0)
                if node:
                    if node.left:
                        nextLevel.append(node.left)
                    if node.right:
                        nextLevel.append(node.right)
            currLevel = nextLevel
            if currLevel:
                levelOrder.append([node.val for node in currLevel])
        return levelOrder
