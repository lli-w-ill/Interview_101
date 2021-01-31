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
            return 2**leftHeight + self.countNodes(root.right)
        else:
            return 2**rightHeight + self.countNodes(root.left)

    def countHeight(self, node: TreeNode) -> int:
        if not node:
            return 0
        return max(self.countHeight(node.left), self.countHeight(node.right)) + 1

# 想法来源：https://leetcode-cn.com/problems/count-complete-tree-nodes/solution/chang-gui-jie-fa-he-ji-bai-100de-javajie-fa-by-xia/
# 时间复杂度：O(h) + O(h) + O(logn * logn)