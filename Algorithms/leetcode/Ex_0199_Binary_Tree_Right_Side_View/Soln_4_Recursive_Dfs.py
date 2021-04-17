# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None, next=None):
#         self.val = val
#         self.left = left
#         self.right = right
#         self.next = next

class Solution_4:
    def rightSideView(self, root: TreeNode) -> List[int]:
        return self.dfs(root, 0, [])

    def dfs(self, node: TreeNode, depth: int, rightView: List[int]) -> List[int]:
        if not node:
            return rightView
        if depth == len(rightView):
            rightView.append(node.val)
        # 先访问右节点
        _ = self.dfs(node.right, depth+1, rightView)
        _ = self.dfs(node.left, depth+1, rightView)
        return rightView


# 参考题解：https://leetcode-cn.com/problems/binary-tree-right-side-view/solution/jian-dan-bfsdfs-bi-xu-miao-dong-by-sweetiee/
