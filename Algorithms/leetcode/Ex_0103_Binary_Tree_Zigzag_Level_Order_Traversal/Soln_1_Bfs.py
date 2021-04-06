# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution_1:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return []
        level = 1
        currLevel = [root]
        zigzagOrder = []
        while currLevel:
            nextLevel = []
            if level % 2 == 1:
                # scan nodes from left to right
                zigzagOrder.append([node.val for node in currLevel])
            else:
                # scan nodes from right to left
                zigzagOrder.append([node.val for node in currLevel][::-1])
            level += 1
            while currLevel:
                node = currLevel.pop(0)
                if node.left:
                    nextLevel.append(node.left)
                if node.right:
                    nextLevel.append(node.right)
            currLevel = nextLevel
        return zigzagOrder
