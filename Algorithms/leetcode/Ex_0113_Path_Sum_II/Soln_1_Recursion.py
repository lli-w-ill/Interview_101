# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution_1:
    def pathSum(self, root: TreeNode, targetSum: int) -> List[List[int]]:
        ans = []
        self.helper(root, targetSum, ans, [])
        return ans

    def helper(self, root: TreeNode, targetSum: int, paths: List[List[int]], currPath: List[int]) -> None:
        # base cases
        if not root and targetSum == 0:
            return
        if not root and targetSum != 0:
            return
        if root and not root.left and not root.right and root.val == targetSum:
            currPath.append(root.val)
            paths.append(currPath[:])
            return

        if root.left:
            self.helper(root.left, targetSum - root.val,
                        paths, currPath + [root.val])
        if root.right:
            self.helper(root.right, targetSum - root.val,
                        paths, currPath + [root.val])
