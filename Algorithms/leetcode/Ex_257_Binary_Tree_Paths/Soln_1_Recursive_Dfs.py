# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        return self.dfs(root, '', [])

    def dfs(self, node: TreeNode, cur: str, path: List[str]) -> List[str]:
        # base cases
        if not node:
            return path
        if not node.left and not node.right:
            path.append(cur + str(node.val))
            return path

        cur += str(node.val) + "->"
        if node.left:
            _ = self.dfs(node.left, cur, path)
        if node.right:
            _ = self.dfs(node.right, cur, path)
        return path
