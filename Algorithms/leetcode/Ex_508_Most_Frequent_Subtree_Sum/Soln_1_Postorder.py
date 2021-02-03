# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import Counter


class Solution:
    def findFrequentTreeSum(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        # key: TreeNode
        # val: 以key为根的子树元素和
        subtreeSum = {}
        _ = self.postorder(root, subtreeSum)
        counter = Counter(subtreeSum.values())
        mostFrequency = counter.most_common(1)[0][1]
        return [li[0] for li in counter.most_common() if li[1] == mostFrequency]

    def postorder(self, node: TreeNode, subtreeSum: Dict[TreeNode, int]) -> int:
        if not node:
            return 0
        leftSubtreeSum = self.postorder(node.left, subtreeSum)
        rightSubtreeSum = self.postorder(node.right, subtreeSum)
        subtreeSum[node] = leftSubtreeSum + rightSubtreeSum + node.val
        return subtreeSum[node]
