# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countNodes(self, root: TreeNode) -> int:
        if not root:
            return 0
        leftHeight = self.countHeight(root.left)
        rightHeight = self.countHeight(root.right)
        if leftHeight == rightHeight:
            return (1 << leftHeight) + self.countNodes(root.right)
        else:
            return (1 << rightHeight) + self.countNodes(root.left)

    def countHeight(self, node: TreeNode) -> int:
        height = 0
        while node:
            node = node.left
            height += 1
        return height

# 想法来源：https://leetcode-cn.com/problems/count-complete-tree-nodes/solution/chang-gui-jie-fa-he-ji-bai-100de-javajie-fa-by-xia/
# 时间复杂度：O(h) + O(h) + O(logn * logn)
# 优化点：1. countHeight改为迭代计算；乘方使用移位计算；
