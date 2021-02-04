# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:
        if not s and not t:
            return True
        if not s or not t:
            return False
        return self.testEqual(s, t) or self.isSubtree(s.left, t) or self.isSubtree(s.right, t)

    def testEqual(self, r1: TreeNode, r2: TreeNode) -> bool:
        # 检查以r1, r2为根的两个树是否相同
        if not r1 and not r2:
            return True
        if not r1 or not r2:
            return False
        return (r1.val == r2.val) and self.testEqual(r1.left, r2.left) and self.testEqual(r1.right, r2.right)


# 参考：https://leetcode-cn.com/problems/subtree-of-another-tree/solution/dui-cheng-mei-pan-duan-zi-shu-vs-pan-duan-xiang-de/
