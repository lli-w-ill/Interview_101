# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def largestValues(self, root: TreeNode) -> List[int]:
        levelMax = []
        self.dfs(root, levelMax, 0)
        return levelMax

    def dfs(self, node: TreeNode, levelMax: List[int], depth: int) -> None:
        if not node:
            return
        if depth == len(levelMax):
            # 第一次进入depth层
            levelMax.append(node.val)
        elif depth < len(levelMax):
            if node.val > levelMax[depth]:
                levelMax[depth] = node.val
        self.dfs(node.left, levelMax, depth+1)
        self.dfs(node.right, levelMax, depth+1)
