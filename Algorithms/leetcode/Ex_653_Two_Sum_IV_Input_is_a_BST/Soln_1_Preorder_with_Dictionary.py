# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTarget(self, root: TreeNode, k: int) -> bool:
        if not root:
            return False
        if not root.left and not root.right:
            return False
        dic = collections.defaultdict(int)   # key: node值，val: 出现次数
        stack = [root]
        while stack:
            node = stack.pop()
            if node.right:
                stack.append(node.right)
            if node.left:
                stack.append(node.left)
            if dic[k - node.val] == 1:
                return True
            dic[node.val] += 1
        return False


# 解法参考Ex1: Two Sum的解法
# 迭代法先序遍历参考Ex144: Binary Tree Preorder Traversal
