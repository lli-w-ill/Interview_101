# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution_2:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        ans = []
        currNode = root
        while currNode:
            if currNode.left:
                # 将 currNode 成为 currNode 左子树的“最右节点”的右孩子
                rightmost = currNode.left
                while rightmost.right:
                    rightmost = rightmost.right
                rightmost.right = currNode
                # 并且断开 currNode 和 currNode 的左孩子
                temp = currNode
                currNode = currNode.left
                temp.left = None
            else:
                ans.append(currNode.val)
                currNode = currNode.right
        return ans
