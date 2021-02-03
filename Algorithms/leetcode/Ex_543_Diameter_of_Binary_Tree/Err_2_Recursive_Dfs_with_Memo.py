# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        # 记录以每个TreeNode为根的子树的diameter
        self.diameterDict = {}

    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        if not root:
            return 0
        if root in self.diameterDict:
            return self.diameterDict[root]
        # 三种情况：
        # 第一种情况：最长路径穿过root节点
        # 第二种情况：最长路径在root的左子树
        # 第三种情况：最长路径在root的右子树
        leftSubtreeDiameter = self.diameterOfBinaryTree(root.left)
        rightSubtreeDiameter = self.diameterOfBinaryTree(root.right)
        passRootDiameter = self.dfs(root.left) + self.dfs(root.right)
        self.diameterDict[root] = max(
            leftSubtreeDiameter, rightSubtreeDiameter, passRootDiameter)
        return self.diameterDict[root]

    def dfs(self, node: TreeNode) -> int:
        if not node:
            return 0   # 空节点
        if not node.left and not node.right:
            return 1   # 叶子结点
        if node in self.diameterDict:
            return self.diameterDict[node]
        self.diameterDict[node] = max(
            self.dfs(node.left), self.dfs(node.right)) + 1
        return self.diameterDict[node]


# 为什么不对呢？
# 错误测试用例：[2,3,null,1]
# 预期结果：2
# 输出结果：1
