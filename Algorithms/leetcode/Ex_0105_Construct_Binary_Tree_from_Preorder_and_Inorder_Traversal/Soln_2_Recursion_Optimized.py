# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution_2:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        # thanks for no repetition
        # v1. for loop
        # for i in range(0, len(inorder)):
        #     imap[inorder[i]] = i
        # v2. list comprehension
        return self.build(preorder, 0, len(preorder), inorder, 0, len(inorder), {inorder[i]: i for i in range(0, len(inorder))})

    def build(self, preorder: List[int], p_start: int, p_end: int, inorder: List[int], i_start: int, i_end: int, imap: Dict[int, int]) -> TreeNode:
        if p_start == p_end:
            return None
        # construct the root node
        root = TreeNode(preorder[p_start])
        # find the root's index in inorder array
        root_idx = imap.get(preorder[p_start], -1)
        if root_idx == -1:
            # root's value doesn't find in inorder array
            return None
        # recursively build left and right subtrees
        numOfNodesInLeft = root_idx - i_start
        root.left = self.build(preorder, p_start+1, p_start +
                               numOfNodesInLeft+1, inorder, i_start, root_idx, imap)
        root.right = self.build(
            preorder, p_start+numOfNodesInLeft+1, p_end, inorder, root_idx+1, i_end, imap)
        return root


# 参考：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by--22/
