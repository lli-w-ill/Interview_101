# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        cur1 = root
        cur2 = None
        po = []
        # 构建morris连接线
        while cur1:
            cur2 = cur1.left
            if cur2:
                while cur2.right and cur2.right != cur1:
                    cur2 = cur2.right
                if cur2.right:
                    # 说明我们重新回到了一个节点，且这个节点的左子树的最右节点已经连接到了该节点，所以我们切断morris连接线
                    cur2.right = None
                else:
                    # 构建最右节点cur2到cur1的连接线
                    po.append(cur1.val)
                    cur2.right = cur1
                    cur1 = cur1.left
                    continue
            else:
                # 如果没有左节点，则直接访问当前节点，然后向右
                po.append(cur1.val)
            cur1 = cur1.right
        return po

# 参考：https://leetcode-cn.com/problems/binary-tree-preorder-traversal/solution/leetcodesuan-fa-xiu-lian-dong-hua-yan-shi-xbian-2/
