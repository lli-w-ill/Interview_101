# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution_1:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        ans = []
        self.inorder(root, ans)
        return ans

    def inorder(self, currNode: TreeNode, currList: List[int]) -> None:
        if currNode is None:
            return
        if currNode.left:
            self.inorder(currNode.left, currList)
        currList.append(currNode.val)
        if currNode.right:
            self.inorder(currNode.right, currList)
