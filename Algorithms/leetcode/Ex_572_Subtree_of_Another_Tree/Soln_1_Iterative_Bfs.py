# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:
        # 题目说明了是两个非空二叉树
        # if not s:
        #     if not t: return True
        #     else: return False
        queue = [s]
        while queue:
            size = len(queue)
            for i in range(size):
                node = queue.pop(0)
                if node.val == t.val and self.testEqual(node, t):
                    return True
                if node.right:
                    queue.append(node.right)
                if node.left:
                    queue.append(node.left)
        return False

    def testEqual(self, r1: TreeNode, r2: TreeNode) -> bool:
        # 检查以r1, r2为根的两个树是否相同
        if not r1 and not r2:
            return True
        elif r1 and r2:
            return (r1.val == r2.val) and self.testEqual(r1.left, r2.left) and self.testEqual(r1.right, r2.right)
        else:
            return False
