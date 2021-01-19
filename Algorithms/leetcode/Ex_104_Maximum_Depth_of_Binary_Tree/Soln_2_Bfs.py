# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        level_queue = []
        level_queue.append(root)
        depth = 0
        if root is None:
            return depth
        while level_queue:
            new_level_queue = []
            while level_queue:
                node = level_queue.pop(0)
                if node.left:
                    new_level_queue.append(node.left)
                if node.right:
                    new_level_queue.append(node.right)
            depth += 1
            level_queue = new_level_queue
        return depth


# 想法来源：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/solution/er-cha-shu-de-zui-da-shen-du-by-leetcode-solution/
