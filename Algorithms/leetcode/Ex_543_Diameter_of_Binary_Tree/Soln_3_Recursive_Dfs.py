# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        # 记录以每个TreeNode为根的子树的diameter
        # self.height = {None: 0}
        self.diameter = 0

    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        self.depth(root)
        return self.diameter

    def depth(self, node: TreeNode):
        # if node in self.height: return self.height[node]
        if not node:
            return 0
        # 左子树的高度（或深度）
        left = self.depth(node.left)
        # 右子树的高度（或深度）
        right = self.depth(node.right)
        # 如果以node为根结点的diameter
        diameter = left + right
        # self.height[node] = diameter
        self.diameter = max(self.diameter, diameter)
        # 如果不以node为根结点，则返回上一层的应该是左右子树中较高（或较深）的那一个
        return max(left, right) + 1


# 参考：https://leetcode-cn.com/problems/diameter-of-binary-tree/solution/hot-100-9er-cha-shu-de-zhi-jing-python3-di-gui-ye-/
# 问题：为什么不用self.height这个备忘录，时间比用备忘录更快呢？
