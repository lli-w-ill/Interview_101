# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution_2:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        po = []
        stack = [root]
        while stack:
            node = stack.pop()
            if not node:
                break
            # visit the current node
            po.append(node.val)
            # add the right node
            if node.right:
                stack.append(node.right)
            # add the left node
            if node.left:
                stack.append(node.left)
        return po


# 三种遍历递归／迭代解法详解参见：https://leetcode-cn.com/problems/binary-tree-preorder-traversal/solution/leetcodesuan-fa-xiu-lian-dong-hua-yan-shi-xbian-2/
