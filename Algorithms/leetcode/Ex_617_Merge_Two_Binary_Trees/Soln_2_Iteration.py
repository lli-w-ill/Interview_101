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
        stack = [(t1, t2)]
        while stack:
            p1, p2 = stack.pop()
            if p2:
                p1.val += p2.val
                # 合并左子树
                if p1.right and p2.right:
                    stack.append((p1.right, p2.right))
                elif p1.right:
                    pass
                elif p2.right:
                    p1.right = p2.right
                # 合并右子树
                if p1.left and p2.left:
                    stack.append((p1.left, p2.left))
                elif p1.left:
                    pass
                elif p2.left:
                    p1.left = p2.left
            else:
                continue
        return t1


# 这道题可以直接在一个树上操作，不用额外再分配空间
# 如果一棵树有，而另一棵树没有，可以直接交错指针过去
