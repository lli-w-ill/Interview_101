# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution_2:
    def rob(self, root: TreeNode) -> int:
        if not root:
            return 0
        # 第一种情况：记录父房屋(root.parent)被偷时，当前房屋(root)可以偷的最高金额
        parentRobbed = {}
        # 第二种情况：记录父房屋(root.parent)没被偷时，当前房屋(root)可以偷的最高金额
        parentNotRobbed = {}
        return self.helper(root, False, parentRobbed, parentNotRobbed)

    def helper(self, node: TreeNode, robParent: bool, parentRobbed: Dict[TreeNode, int], parentNotRobbed: Dict[TreeNode, int]) -> int:
        if not node:
            return 0
        # 如果父房屋被偷了
        if robParent:
            # 如果parentRobbed中已经记录过最高金额，则直接返回结果
            if node in parentRobbed:
                return parentRobbed[node]
            else:
                # 将问题传给当前房屋(node)的左右孩子，并置robParent为False，然后在parentRobbed中记录最高金额
                money = self.helper(node.left, False, parentRobbed, parentNotRobbed) + \
                    self.helper(node.right, False,
                                parentRobbed, parentNotRobbed)
                parentRobbed[node] = money
                return money
        # 如果父房屋没有被偷
        else:
            # 如果parentNotRobbed中已经记录过最高金额，则直接返回结果
            if node in parentNotRobbed:
                return parentNotRobbed[node]
            else:
                # 偷当前房子，并把问题传给当前房屋(node)的左右孩子，并置robParent为True，然后在parentNotRobbed中记录最高金额
                moneyRobCur = node.val + self.helper(node.left, True, parentRobbed, parentNotRobbed) + self.helper(
                    node.right, True, parentRobbed, parentNotRobbed)
                # 不偷当前房子，并把问题直接传给当前房屋(node)的左右孩子
                moneyNoRubCur = self.helper(node.left, False, parentRobbed, parentNotRobbed) + self.helper(
                    node.right, False, parentRobbed, parentNotRobbed)
                parentNotRobbed[node] = max(moneyRobCur, moneyNoRubCur)
                return max(moneyRobCur, moneyNoRubCur)


# 参考：leetcode.com之前提交的结果
