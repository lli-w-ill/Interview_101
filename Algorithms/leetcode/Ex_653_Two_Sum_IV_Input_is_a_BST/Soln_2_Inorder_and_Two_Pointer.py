# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTarget(self, root: TreeNode, k: int) -> bool:
        inorder = []
        curr = root
        stack = []
        while stack or curr:
            if curr:
                stack.append(curr)
                curr = curr.left    # 访问左节点需要优先与根结点
            else:
                # 说明已经到达最左边节点，且当前curr为空
                curr = stack.pop()
                # 访问当前节点
                inorder.append(curr.val)
                # 访问右节点
                curr = curr.right    # 这里无需判断是否右孩子，如果右孩子为空，则下一个循环直接取stack中最后一个node
        l, r = 0, len(inorder)-1
        while l < r:
            ssum = inorder[l] + inorder[r]
            if ssum == k:
                return True
            elif ssum > k:
                r -= 1
            else:
                l += 1
        return False


# 迭代中序遍历参考：Ex530/Soln_1_Iterative_Inorder.py
