# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        itor = root
        while itor:
            if itor.left:
                if itor.left.right:
                    # 如果itor.left有右子树，那么需要把itor.left的右子树转嫁接到itor.left左子树中的最大节点的右孩子
                    if not itor.left.left:
                        # 如果itor.left的左子树为空，则直接将itor.left.left置为itor.left的右子树，然后将itor.left的右子树置空
                        itor.left.left = itor.left.right
                        itor.left.right = None
                    else:
                        # 如果itor.left的左子树不为空，则需要找到itor.left左子树中最大的节点（这里命名为left_left_largest），且left_left_largest需要满足：右子树必须空，左子树可以为空或不为空
                        left_left_largest = self.findNode(itor.left.left)
                        left_left_largest.right = itor.left.right
                        itor.left.right = None
                # 当腾空itor.left的右子树后，把itor右子树嫁接到itor.left的右孩子处
                itor.left.right = itor.right
                # 然后与Soln_1思路相同，交换itor的左右孩子，使左孩子为空，然后移动到下一个节点
                itor.left, itor.right = None, itor.left
                itor = itor.right
            else:
                itor = itor.right

    def findNode(self, node: TreeNode) -> TreeNode:
        # left_left_largest需要满足：右子树必须空，左子树可以为空或不为空
        if not node.left and not node.right:
            return node
        if node.left and not node.right:
            return node
        if (node.left and node.right) or (not node.left and node.right):
            return self.findNode(node.right)


# 注：这个方法参考我在leetcode.com上之前提交的思路
# 这个方法思路上比Soln_1_Iteration.py更难理解一些
