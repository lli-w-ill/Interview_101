# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution_2:
    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        if not root:
            return None
        if root.val > key:
            # 要删的节点在root的左子树
            root.left = self.deleteNode(root.left, key)
        elif root.val < key:
            # 要删的节点在root的右子树
            root.right = self.deleteNode(root.right, key)
        else:
            # root就是要删的节点
            # 第一种情况：如果root没有左子树
            if not root.left:
                return root.right
            # 第二种情况：如果root没有右子树
            elif not root.right:
                return root.left
            # 第三种情况：如果root有左右子树
            else:
                # 需要把root的左子树挂在root右子树的最左节点的左孩子处
                target = root.right
                while target.left:
                    target = target.left
                target.left = root.left
                # 然后返回root右子树的根节点即可
                return root.right
        return root


# 参考题解：https://leetcode-cn.com/problems/delete-node-in-a-bst/solution/450-shan-chu-er-cha-sou-suo-shu-zhong-de-jie-dia-6/
