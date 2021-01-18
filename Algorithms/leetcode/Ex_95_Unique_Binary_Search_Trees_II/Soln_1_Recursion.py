# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:
        if n == 0:
            return []
        return self.getAnswers(1, n)

    def getAnswers(self, start: int, end: int) -> List[TreeNode]:
        ans = []
        if start > end:
            # return an empty tree
            ans.append(None)
            return ans
        elif start == end:
            ans.append(TreeNode(start))
            return ans
        else:
            for root in range(start, end+1):
                allPossibleLeftSubtrees = self.getAnswers(start, root - 1)
                allPossibleRightSubtrees = self.getAnswers(root + 1, end)
                # 两两组合
                for leftSubtree in allPossibleLeftSubtrees:
                    for rightSubtree in allPossibleRightSubtrees:
                        rootNode = TreeNode(root, leftSubtree, rightSubtree)
                        ans.append(rootNode)
        return ans


# 参考：https://leetcode-cn.com/problems/unique-binary-search-trees-ii/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-2-7/
