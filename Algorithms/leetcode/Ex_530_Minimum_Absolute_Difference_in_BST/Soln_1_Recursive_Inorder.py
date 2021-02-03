# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getMinimumDifference(self, root: TreeNode) -> int:
        if not root:
            return 0
        if not root.left and not root.right:
            return 0

        self.minDiff = float('inf')
        self.inorder(root, [])
        return self.minDiff

    def inorder(self, curr: TreeNode, io: List[int]) -> None:
        if not curr:
            return
        # 左
        self.inorder(curr.left, io)
        # 中
        if io:
            prevVal = io[-1]
        else:
            prevVal = None
        if prevVal is not None and curr.val - prevVal < self.minDiff:
            self.minDiff = curr.val - prevVal
        io.append(curr.val)
        # 右
        self.inorder(curr.right, io)


# inorder的迭代和递归实现参考：https://www.techiedelight.com/inorder-tree-traversal-iterative-recursive/
