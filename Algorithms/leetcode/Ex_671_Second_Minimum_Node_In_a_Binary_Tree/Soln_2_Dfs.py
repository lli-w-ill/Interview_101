# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findSecondMinimumValue(self, root: TreeNode) -> int:
        if not root:
            return -1
        minVal = root.val
        self.ans = float('inf')
        self.dfs(root, minVal)
        if self.ans == float('inf'):
            return -1
        else:
            return self.ans

    def dfs(self, node: TreeNode, minVal: int) -> int:
        if node.val > minVal and node.val < self.ans:
            self.ans = node.val
        if node.left and node.right:
            self.dfs(node.left, minVal)
            self.dfs(node.right, minVal)


# 参考：https://leetcode-cn.com/problems/second-minimum-node-in-a-binary-tree/solution/dfsdi-gui-0ms-by-cyingenohalt-6qc4/
