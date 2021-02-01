# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        paths = []
        if not root:
            return paths
        stack = [root]
        curPathVal = [[str(root.val)]]
        while stack:
            node = stack.pop()
            path = curPathVal.pop()
            if not node.left and not node.right:
                paths.append('->'.join(path))
            if node.right:
                stack.append(node.right)
                curPathVal.append(path + [str(node.right.val)])
            if node.left:
                stack.append(node.left)
                curPathVal.append(path + [str(node.left.val)])
        return paths


# 递归法和迭代法dfs参考：https://leetcode-cn.com/problems/binary-tree-paths/solution/257-er-cha-shu-de-suo-you-lu-jing-tu-wen-jie-xi-by/
