'''
相对于解法3，解法4优化的地方在于：不需要把整个中序遍历的数都存下来，只需要比较当前中序遍历的数和上一个中序遍历的数，就可以得知是不是合法的二叉搜索树
但是，总体的时间复杂度还是O(n)，因为最坏情况是所有节点组成向左倾斜的单链
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        stack = []
        prev_inorder = None
        while stack or root:
            # push nodes until the leftmost
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            # check validity
            if prev_inorder is not None and \
                    root.val <= prev_inorder:
                return False
            # update
            prev_inorder = root.val
            root = root.right
        return True


# 参考：https://leetcode-cn.com/problems/validate-binary-search-tree/solution/yan-zheng-er-cha-sou-suo-shu-by-leetcode-solution/
