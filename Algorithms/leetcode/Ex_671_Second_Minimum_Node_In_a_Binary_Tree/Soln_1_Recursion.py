# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findSecondMinimumValue(self, root: TreeNode) -> int:
        if not root:
            return -1
        if not root.left and not root.right:
            return -1
        # 一共五种情况：
        #    2        2        2        2        2
        #   / \      / \      / \      / \      / \
        #  2   2    3   3    2   3    3   2    3   4
        #   (1)      (2)     (3)      (4)      (5)
        # 第一种情况
        if root.left.val == root.right.val == root.val:
            # 这种情况需要分别求出左子树的第二小和右子树的第二小，比较两个值的大小，以及和-1的关系
            # 返回较小的非-1的第二小
            leftSecondMin = self.findSecondMinimumValue(root.left)
            rightSecondMin = self.findSecondMinimumValue(root.right)
            if leftSecondMin == -1:
                return rightSecondMin
            if rightSecondMin == -1:
                return leftSecondMin
            if leftSecondMin < rightSecondMin:
                return leftSecondMin
            else:
                return rightSecondMin
        # 第二种情况
        elif root.left.val == root.right.val:
            # 这种情况返回任意一个值即可
            return root.left.val
        # 第三种情况
        elif root.left.val == root.val < root.right.val:
            # 这种情况需要先求左子树的第二小，比较左子树第二小与直接右孩子值的关系
            # 如果左子树第二小比直接右孩子的值更小或相等，则返回任意一个值即可
            # 如果左子树第二小大于直接右孩子，则返回直接右孩子的值即可
            leftSecondMin = self.findSecondMinimumValue(root.left)
            if leftSecondMin != -1 and leftSecondMin <= root.right.val:
                return leftSecondMin
            else:
                return root.right.val
        # 第四种情况
        elif root.right.val == root.val < root.left.val:
            # 与第三种情况互为对称，不再赘述
            rightSecondMin = self.findSecondMinimumValue(root.right)
            if rightSecondMin != -1 and rightSecondMin <= root.left.val:
                return rightSecondMin
            else:
                return root.left.val
        # 第五种情况
        elif root.val != root.left.val != root.right.val:
            # 返回较小的值即可
            if root.left.val < root.right.val:
                return root.left.val
            else:
                return root.right.val
