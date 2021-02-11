# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def addOneRow(self, root: TreeNode, v: int, d: int) -> TreeNode:
        if not root:
            return None
        if d == 1:
            # 创建一个新节点，作为新的根结点，旧根结点作为新根结点的左孩子
            newRoot = TreeNode(v)
            newRoot.left = root
            return newRoot
        depth = 1   # 代表当前parent中node的深度
        parent = [root]
        while parent:
            children = []
            if depth + 1 == d:
                # 为所有parent中的节点下面创建新节点，并将当前parent中节点的孩子节点连接到新节点
                for node in parent:
                    # 加左节点
                    newNode = TreeNode(v)
                    newNode.left = node.left
                    node.left = newNode
                    # 加右节点
                    newNode = TreeNode(v)
                    newNode.right = node.right
                    node.right = newNode
                break
            else:
                # run BFS
                for node in parent:
                    if node.left:
                        children.append(node.left)
                    if node.right:
                        children.append(node.right)
                parent = children
            depth += 1
        return root
