# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution_1:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        return self.build(preorder, 0, len(preorder), inorder, 0, len(inorder))

    def build(self, preorder: List[int], p_start: int, p_end: int, inorder: List[int], i_start: int, i_end: int) -> TreeNode:
        if p_start == p_end:
            return None
        # construct the root node
        root = TreeNode(preorder[p_start])
        # find the root's index in inorder array
        root_idx = -1
        for i in range(i_start, i_end):
            if inorder[i] == preorder[p_start]:
                root_idx = i
                break
        if root_idx == -1:
            # root's value doesn't find in inorder array
            return None
        # recursively build left and right subtrees
        numOfNodesInLeft = root_idx - i_start
        root.left = self.build(
            preorder, p_start+1, p_start+numOfNodesInLeft+1, inorder, i_start, root_idx)
        root.right = self.build(
            preorder, p_start+numOfNodesInLeft+1, p_end, inorder, root_idx+1, i_end)
        return root


# 参考：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by--22/
