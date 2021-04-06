# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution_1:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        levelOrder = []
        if root is None:
            return levelOrder
        currLevel = [root]
        while currLevel:
            nextLevel = []
            levelOrder.append([node.val for node in currLevel])
            while currLevel:
                node = currLevel.pop(0)
                if node.left:
                    nextLevel.append(node.left)
                if node.right:
                    nextLevel.append(node.right)
            currLevel = nextLevel
        return levelOrder[::-1]
