# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution_1:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        if not root:
            return 0
        stack = [root]
        leftSum = 0
        while stack:
            node = stack.pop()
            if node.right:
                stack.append(node.right)
            if node.left:
                # 检查是否是左叶节点
                if not node.left.left and not node.left.right:
                    leftSum += node.left.val
                else:
                    stack.append(node.left)
        return leftSum
