# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        cur1 = root
        cur2 = None
        po = []
        while cur1:
            cur2 = cur1.left
            if cur2:
                while cur2.right and cur2.right != cur1:
                    cur2 = cur2.right
                if cur2.right:
                    cur2.right = None
                    self.postorder(cur1.left, po)
                else:
                    cur2.right = cur1
                    cur1 = cur1.left
                    continue
            cur1 = cur1.right
        self.postorder(root, po)
        return po

    def postorder(self, head: TreeNode, po: List[int]) -> None:
        reverseListHead = self.reverse(head)
        cur = reverseListHead
        while cur:
            po.append(cur.val)
            cur = cur.right
        # reverse back
        _ = self.reverse(head)

    def reverse(self, head: TreeNode) -> TreeNode:
        pre = None
        cur = head
        while cur:
            next = cur.right
            cur.right = pre
            pre = cur
            cur = next
        return pre


# 参考：https://leetcode-cn.com/problems/binary-tree-preorder-traversal/solution/leetcodesuan-fa-xiu-lian-dong-hua-yan-shi-xbian-2/
