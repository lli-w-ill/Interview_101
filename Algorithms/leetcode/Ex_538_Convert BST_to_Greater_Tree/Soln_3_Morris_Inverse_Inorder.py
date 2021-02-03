# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def convertBST(self, root: TreeNode) -> TreeNode:
        sum = 0
        node = root
        while node:
            if not node.right:
                # 如果当前节点的右子节点为空，处理当前节点，并遍历当前节点的左子节点
                sum += node.val
                node.val = sum
                node = node.left
            else:
                # # 找到当前节点右子树的最左节点
                succ = self.getSuccessor(node)

                if not succ.left:
                    # 如果最左节点的左指针为空，将最左节点的左指针指向当前节点，遍历当前节点的右子节点
                    succ.left = node
                    node = node.right
                else:
                    # 如果最左节点的左指针不为空，将最左节点的左指针重新置为空，处理当前节点，并将当前节点置为其左节点
                    succ.left = None
                    sum += node.val
                    node.val = sum
                    node = node.left
        return root

    def getSuccessor(self, node: TreeNode) -> TreeNode:
        # 找到当前节点右子树的最左节点
        succ = node.right
        while succ.left and succ.left != node:
            succ = succ.left
        return succ


# 参考：https://leetcode-cn.com/problems/convert-bst-to-greater-tree/solution/ba-er-cha-sou-suo-shu-zhuan-huan-wei-lei-jia-sh-14/
