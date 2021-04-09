# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution_1:
    def sumNumbers(self, root: TreeNode) -> int:
        ssum = [0]
        self.dfs(root, 0, ssum)
        return ssum[0]

    def dfs(self, node: TreeNode, curr: int, ssum: List[int]) -> None:
        # base cases
        if not node:
            return
        if not node.left and not node.right:
            ssum[0] += curr * 10 + node.val
            return

        if node.left:
            self.dfs(node.left, curr * 10 + node.val, ssum)
        if node.right:
            self.dfs(node.right, curr * 10 + node.val, ssum)
