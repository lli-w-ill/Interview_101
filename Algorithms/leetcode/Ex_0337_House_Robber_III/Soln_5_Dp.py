# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution_5:
    def rob(self, root: TreeNode) -> int:
        return max(self.helper(root))

    def helper(self, root: TreeNode) -> List[int]:
        # index 0: 表示不偷当前节点的最大金额
        # index 1: 表示偷当前节点的最大金额
        if not root:
            return [0, 0]

        left = self.helper(root.left)
        right = self.helper(root.right)

        # 第一种情况(对应index1)：偷当前节点(root)，左右孩子都不能偷
        case1 = root.val + left[0] + right[0]
        # 第二种情况(对应index0)：不偷当前节点(root)，左右孩子可偷可不偷
        case2 = max(left) + max(right)
        return [case2, case1]


# 参考：https://leetcode-cn.com/problems/house-robber-iii/solution/san-chong-fang-fa-jie-jue-shu-xing-dong-tai-gui-hu/
