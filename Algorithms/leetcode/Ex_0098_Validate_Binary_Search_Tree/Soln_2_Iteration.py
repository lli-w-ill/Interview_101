# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution_2:
    def isValidBST(self, root: TreeNode) -> bool:
        self.lowers = []  # lower bound
        self.uppers = []  # upper bound
        self.stack = []
        self.insert(root)

        while self.stack:
            curr = self.stack.pop()
            lower = self.lowers.pop()
            upper = self.uppers.pop()

            if curr is None:
                # empty subtree is a valid binary search tree
                continue
            if lower is not None and curr.val <= lower:
                return False
            if upper is not None and curr.val >= upper:
                return False

            self.insert(curr.left, lower, curr.val)
            self.insert(curr.right, curr.val, upper)

        return True

    def insert(self, node: TreeNode, lowerVal: int = None, upperVal: int = None) -> bool:
        self.stack.append(node)
        self.lowers.append(lowerVal)
        self.uppers.append(upperVal)


# 参考：https://leetcode-cn.com/problems/validate-binary-search-tree/solution/yan-zheng-er-cha-sou-suo-shu-by-leetcode-solution/
