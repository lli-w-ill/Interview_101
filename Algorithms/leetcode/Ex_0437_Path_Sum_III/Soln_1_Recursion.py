# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution_1:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        if not root:
            return 0
        # 第一种情况：路径包括root节点
        case1 = self.helper(root, sum, 0)
        # 第二种情况：路径不包括root节点，且路径在root的左子树中
        case2 = self.pathSum(root.left, sum)
        # 第三种情况：路径不包括root节点，且路径在root的右子树中
        case3 = self.pathSum(root.right, sum)

        return case1 + case2 + case3

    def helper(self, node: TreeNode, sum: int, curSum: int) -> int:
        if not node:
            return 0
        # 第一种情况：截止到当前节点，已经找到一条路径总和为sum的值
        # （但是团长不要停下来啊，也许继续往下还可找到另一条符合的路径，即当前满足的路径下面可能接了一段总和为0的路径）
        case1 = 1 if node.val == sum - curSum else 0
        # 第二种情况：向左边找，并更新curSum
        case2 = self.helper(node.left, sum, curSum + node.val)
        # 第三种情况：向右边找，并更新curSum
        case3 = self.helper(node.right, sum, curSum + node.val)

        return case1 + case2 + case3
