# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return []
        zigzagOrder = []
        self.dfs(root, zigzagOrder, 1)  # 根结点认为level=1
        return zigzagOrder

    def dfs(self, node: TreeNode, zigzagOrder: List[List[int]], level: int) -> None:
        if node is None:
            return
        if level > len(zigzagOrder):
            # 证明新一层的list order还没有创建，所以需要首先创造新一层的list
            zigzagOrder.append([])
        if level % 2 == 1:
            # add value at the end
            zigzagOrder[level - 1].append(node.val)
        else:
            # add value at the beginning to make reverse order
            zigzagOrder[level - 1].insert(0, node.val)
        self.dfs(node.left, zigzagOrder, level + 1)
        self.dfs(node.right, zigzagOrder, level + 1)


# 想法来源：https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/solution/bfshe-dfsliang-chong-jie-jue-fang-shi-by-184y/
