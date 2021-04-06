# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution_1:
    def isBalanced(self, root: TreeNode) -> bool:
        if not root:
            return True
        # None node has zero height
        self.hmap: Dict[TreeNode, int] = {None: 0}
        self.hmap[root] = self.getHeight(root)
        for key in self.hmap.keys():
            if key and abs(self.hmap[key.left] - self.hmap[key.right]) > 1:
                return False
        return True

    def getHeight(self, node: TreeNode) -> int:
        if node is None:
            return 0
        else:
            if self.hmap.get(node.left, None) is None:
                lh = self.getHeight(node.left)
            else:
                lh = self.hmap[node.left]
            if self.hmap.get(node.right, None) is None:
                rh = self.getHeight(node.right)
            else:
                rh = self.hmap[node.right]
            h = max(lh, rh) + 1
            if self.hmap.get(node, None) is None:
                self.hmap[node] = h
            return h
