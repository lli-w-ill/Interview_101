# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import Counter


class Solution:
    def findMode(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        preorder = []
        self.preorder(root, preorder)
        counter = Counter(preorder)
        mostFrequency = counter.most_common(1)[0][1]
        return [li[0] for li in counter.most_common() if li[1] == mostFrequency]

    def preorder(self, node: TreeNode, po: List[int]) -> None:
        if not node:
            return
        po.append(node.val)
        self.preorder(node.left, po)
        self.preorder(node.right, po)
