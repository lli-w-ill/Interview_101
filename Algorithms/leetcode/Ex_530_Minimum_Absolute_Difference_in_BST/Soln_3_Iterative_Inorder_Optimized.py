# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getMinimumDifference(self, root: TreeNode) -> int:
        stack = []
        preVal = -float('inf')
        minVal = float('inf')
        cur = root
        while cur or stack:
            while cur:
                stack.append(cur)
                cur = cur.left
            cur = stack.pop()
            if cur.val - preVal < minVal:
                minVal = cur.val - preVal
            preVal = cur.val
            cur = cur.right
        return minVal


# 参考：https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/solution/zhong-xu-bian-li-tuan-mie-xi-lie-er-cha-sou-suo-sh/
# 优化点在于空间复杂度，相比较Soln_1，Soln_3这个解法不需要存储整个inorder的值
