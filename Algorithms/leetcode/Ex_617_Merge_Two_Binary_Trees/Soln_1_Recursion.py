# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def mergeTrees(self, t1: TreeNode, t2: TreeNode) -> TreeNode:
        if not t1:
            return t2    # 如果默认基准树t1是空，则直接返回t2
        p1, p2 = t1, t2
        _ = self.merge(p1, p2)
        return t1   # 默认以t1为基准树

    def merge(self, p1: TreeNode, p2: TreeNode) -> TreeNode:
        if p1 and p2:
            p1.val += p2.val
            p1.left = self.merge(p1.left, p2.left)
            p1.right = self.merge(p1.right, p2.right)
            return p1
        elif p1:
            return p1
        elif p2:
            return p2
        else:
            return None


# 这道题可以直接在一个树上操作，不用额外再分配空间
# 如果一棵树有，而另一棵树没有，可以直接交错指针过去
