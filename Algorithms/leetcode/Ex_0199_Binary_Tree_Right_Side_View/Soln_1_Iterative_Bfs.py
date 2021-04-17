# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution_1:
    def rightSideView(self, root: TreeNode) -> List[int]:
        rightView = []
        if not root:
            return rightView
        parents = [root]
        while parents:
            rightView.append(parents[-1].val)
            children = []
            for node in parents:
                if node.left:
                    children.append(node.left)
                if node.right:
                    children.append(node.right)
            parents = children
        return rightView
