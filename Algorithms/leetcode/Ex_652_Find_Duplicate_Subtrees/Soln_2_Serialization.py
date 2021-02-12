# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import Counter


class Solution:
    def findDuplicateSubtrees(self, root: TreeNode) -> List[TreeNode]:
        cnt = Counter()
        ans = []

        def serialize(node: TreeNode) -> str:
            if not node:
                return '#'
            serial = '{},{},{}'.format(node.val, serialize(
                node.left), serialize(node.right))
            cnt[serial] += 1
            if cnt[serial] == 2:
                ans.append(node)
            return serial
        serialize(root)
        return ans

# 参考：https://leetcode.com/problems/find-duplicate-subtrees/solution/
# 该解法借鉴Ex449: Serialize and deserialize bst的解法
