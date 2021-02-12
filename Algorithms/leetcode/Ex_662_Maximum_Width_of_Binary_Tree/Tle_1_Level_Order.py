# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def widthOfBinaryTree(self, root: TreeNode) -> int:
        maxDepth = 0
        if not root:
            return maxDepth

        def height(node: TreeNode = root) -> int:
            return 0 if not node else 1 + max(height(node.left), height(node.right))
        h = height(root)
        queue = [root]
        for i in range(h):
            size = len(queue)
            # 找到第一个非None的节点的下标，和最后一个非None的节点的下标
            lo, hi = 0, size - 1
            while lo <= hi and not queue[lo]:
                lo += 1
            while hi >= lo and not queue[hi]:
                hi -= 1
            # 更新maxDepth
            if hi + 1 - lo > maxDepth:
                maxDepth = hi + 1 - lo
            # 将下一层节点（包括空节点）加入到queue
            for i in range(size):
                node = queue.pop(0)
                if not node:
                    queue.append(None)
                    queue.append(None)
                    continue
                if not node.left:
                    queue.append(None)
                else:
                    queue.append(node.left)
                if not node.right:
                    queue.append(None)
                else:
                    queue.append(node.right)

        return maxDepth


# 想法参考Ex655: Print Binary Tree的解法
