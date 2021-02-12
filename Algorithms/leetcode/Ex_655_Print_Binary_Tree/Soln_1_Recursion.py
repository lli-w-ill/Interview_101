# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def printTree(self, root: TreeNode) -> List[List[str]]:
        def height(node: TreeNode = root) -> int:
            return 0 if not node else 1 + max(height(node.left), height(node.right))

        h = height()
        w = (1 << h) - 1    # 规律推导
        grid = [["" for _ in range(w)] for _ in range(h)]

        def fill(node: TreeNode = root, depth: int = 0, lo: int = 0, hi: int = w-1) -> None:
            if not node:
                return
            mid = (lo + hi) >> 1  # 相当于mid = lo + (hi - lo) // 2
            grid[depth][mid] = str(node.val)
            fill(node.left, depth+1, lo, mid-1)
            fill(node.right, depth+1, mid+1, hi)

        fill()
        return grid

# 参考：https://leetcode-cn.com/problems/print-binary-tree/solution/liang-ci-di-gui-by-supermanblues-2c08/
