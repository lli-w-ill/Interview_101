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
            if itor.right:
                if itor.left:
                    # 如果itor左右子树不为空，那么需要把itor的右子树转嫁接到itor左子树的最大节点右孩子（这里命名为left_biggest），然后将itor的左子树置为右子树，左子树置空
                    left_biggest = itor.left
                    while left_biggest.right:
                        left_biggest = left_biggest.right
                    left_biggest.right = itor.right
                    itor.left, itor.right = None, itor.left
                    itor = itor.right
                else:
                    itor = itor.right
            else:
                # 注意，如果itor只有左子树，则需要交换左右子树，然后itor移动到下一个右节点
                # 在移动到下一个节点之前，始终要保证当前节点的左子树为空，右子树是交换前的左子树
                itor.left, itor.right = None, itor.left
                itor = itor.right
