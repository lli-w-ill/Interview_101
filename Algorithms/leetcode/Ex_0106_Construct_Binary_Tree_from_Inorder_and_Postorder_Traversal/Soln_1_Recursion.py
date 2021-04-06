# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution_1:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        if not inorder or not postorder:
            return None
        if len(inorder) != len(postorder):
            return None
        imap = {inorder[i]: i for i in range(len(inorder))}
        return self.build(inorder, 0, len(inorder) - 1, postorder, 0, len(postorder) - 1, imap)

    def build(self, inorder: List[int], istart: int, iend: int, postorder: List[int], pstart: int, pend: int, imap: Dict[int, int]) -> TreeNode:
        if istart > iend or pstart > pend:
            return None
        root = TreeNode(postorder[pend])
        rootIndex = imap[root.val]
        root.left = self.build(inorder, istart, rootIndex - 1,
                               postorder, pstart, pstart + rootIndex - istart - 1, imap)
        root.right = self.build(inorder, rootIndex + 1, iend,
                                postorder, pstart + rootIndex - istart, pend - 1, imap)
        return root


# 参考：https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/solution/tu-jie-gou-zao-er-cha-shu-wei-wan-dai-xu-by-user72/
