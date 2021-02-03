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
        leftmost = []
        self.dfs(root, leftmost, 1)
        return leftmost[-1]

    def dfs(self, node: TreeNode, leftmost: List[TreeNode], depth: int) -> None:
        if not node:
            return
        if depth > len(leftmost):
            leftmost.append(node.val)
        self.dfs(node.left, leftmost, depth+1)
        self.dfs(node.right, leftmost, depth+1)


# 参考：https://leetcode-cn.com/problems/find-bottom-left-tree-value/solution/yan-du-you-xian-sou-suo-bfs-shen-du-you-lgyhj/
