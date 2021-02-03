# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def convertBST(self, root: TreeNode) -> TreeNode:
        # 根据示例1，可知访问顺序应该是：右->中->左
        stack = []
        cur = root
        sum = 0
        while cur or stack:
            # 右
            while cur:
                stack.append(cur)
                cur = cur.right
            # 中
            cur = stack.pop()
            cur.val += sum
            sum = cur.val
            # 左
            cur = cur.left
        return root
