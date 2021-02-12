# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def widthOfBinaryTree(self, root: TreeNode) -> int:
        if not root:
            return 0
        queue = [root]
        root.val = 1
        maxDepth = 1
        while queue:
            firstTag = queue[0].val     # 当前层第一个节点的编号
            maxDepth = max(maxDepth, queue[-1].val - queue[0].val + 1)
            for i in range(len(queue)):
                node = queue.pop(0)
                node.val -= firstTag
                if node.left:
                    node.left.val = 2 * node.val
                    queue.append(node.left)
                if node.right:
                    node.right.val = 2 * node.val + 1
                    queue.append(node.right)
        return maxDepth


# 参考：https://leetcode-cn.com/problems/maximum-width-of-binary-tree/solution/cceng-xu-bian-li-bu-yong-unsigned-long-long-by-ene/
