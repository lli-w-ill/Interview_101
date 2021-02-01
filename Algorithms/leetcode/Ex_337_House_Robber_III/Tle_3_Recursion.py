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
        # 第一种情况：偷爷爷(root)和其最多四个孙子房屋
        case1 = root.val
        if root.left:
            case1 += self.rob(root.left.left) + self.rob(root.left.right)
        if root.right:
            case1 += self.rob(root.right.left) + self.rob(root.right.right)
        # 第二种情况：不偷爷爷(root)，偷两个孩子房屋
        case2 = self.rob(root.left) + self.rob(root.right)
        return max(case1, case2)


# 参考：https://leetcode-cn.com/problems/house-robber-iii/solution/san-chong-fang-fa-jie-jue-shu-xing-dong-tai-gui-hu/
