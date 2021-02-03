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
        minDiff = float('inf')
        stack = []
        inorder = []
        prev, curr = None, root
        while curr or stack:
            if curr:
                # 左
                stack.append(curr)
                prev, curr = curr, curr.left
            else:
                # 中
                curr = stack.pop()
                if inorder:
                    prev = inorder[-1]
                else:
                    prev = None
                inorder.append(curr)
                if prev is not None and curr.val - prev.val < minDiff:
                    minDiff = curr.val - prev.val
                # 右
                prev, curr = curr, curr.right
        # print([node.val for node in inorder])
        return minDiff


# inorder的迭代和递归实现参考：https://www.techiedelight.com/inorder-tree-traversal-iterative-recursive/
