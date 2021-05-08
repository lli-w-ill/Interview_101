# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution_4:
    def rob(self, root: TreeNode) -> int:
        return self.helper(root, {})

    def helper(self, root: TreeNode, memo: Dict[TreeNode, int]) -> int:
        # base case
        if not root:
            return 0
        if root in memo:
            return memo[root]

        # 第一种情况：偷爷爷(root)和其最多四个孙子房屋
        case1 = root.val
        if root.left:
            case1 += self.helper(root.left.left, memo) + \
                self.helper(root.left.right, memo)
        if root.right:
            case1 += self.helper(root.right.left, memo) + \
                self.helper(root.right.right, memo)
        # 第二种情况：不偷爷爷(root)，偷两个孩子房屋
        case2 = self.helper(root.left, memo) + self.helper(root.right, memo)
        memo[root] = max(case1, case2)
        return memo[root]


# 参考：https://leetcode-cn.com/problems/house-robber-iii/solution/san-chong-fang-fa-jie-jue-shu-xing-dong-tai-gui-hu/
