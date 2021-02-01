# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rob(self, root: TreeNode) -> int:
        if not root:
            return 0
        # 第一种情况：偷当前房屋(root)，然后把问题传给左右两棵子树，且标记其父房屋已被偷
        # 第二种情况：不偷当前房屋(root)，然后直接把问题传给左右两棵子树
        return max(root.val + self.helper(root.left, True) + self.helper(root.right, True),
                   self.rob(root.left) + self.rob(root.right))

    def helper(self, root: TreeNode, robParent: bool) -> int:
        if not root:
            return 0
        # 如果父房屋没被偷，且当前是叶子房屋，那么一定要偷（不偷白不偷）
        if not root.left and not root.right and not robParent:
            return root.val
        # 如果父房屋已被偷，那么直接把问题传给当前房屋(root)的左右子树
        if robParent:
            return self.rob(root.left) + self.rob(root.right)
        # 如果父房屋没被偷，那么相当于rob函数，直接调用计算
        else:
            return self.rob(root)

# 超出时间限制
