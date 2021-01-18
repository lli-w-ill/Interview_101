# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import defaultdict


class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:
        if n == 0:
            return []
        dp = defaultdict(list)
        dp[0] = [None]
        dp[1] = [TreeNode(1)]   # 作为子树序列size为1的代表
        for length in range(2, n+1):    # 要生成子树序列的长度
            for rootVal in range(1, n+1):  # 根结点的值，同样作为clone时的偏移量
                leftSubtreeSize = rootVal - 1   # 左子树序列长度
                rightSubtreeSize = length - rootVal  # 右子树序列长度
                for leftSubtree in dp[leftSubtreeSize]:
                    for rightSubtree in dp[rightSubtreeSize]:
                        root = TreeNode(rootVal, leftSubtree,
                                        self.clone(rightSubtree, rootVal))
                        dp[length].append(root)
        return dp[n]

    def clone(self, rootNode: TreeNode, offset: int) -> TreeNode:
        if rootNode is None:
            return None
        rootCloned = TreeNode(rootNode.val + offset)
        rootCloned.left = self.clone(rootNode.left, offset)
        rootCloned.right = self.clone(rootNode.right, offset)
        return rootCloned


# 参考：https://leetcode-cn.com/problems/unique-binary-search-trees-ii/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-2-7/
