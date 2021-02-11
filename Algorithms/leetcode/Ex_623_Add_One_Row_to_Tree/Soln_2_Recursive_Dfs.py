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
        rootDepth = 1
        self.dfs(root, root.left, rootDepth + 1, v, d)
        self.dfs(root, root.right, rootDepth + 1, v, d)
        return root

    def dfs(self, parent: TreeNode, child: TreeNode, childDepth: int, v: int, d: int) -> None:
        if not parent:
            return
        if childDepth == d:
            # 需要在child层新加节点，作为parent节点的左／右孩子，并把当前child节点“挤”到下一层
            newNode = TreeNode(v)
            if parent.left == child:
                newNode.left = child
                parent.left = newNode
            elif parent.right == child:
                newNode.right = child
                parent.right = newNode
            return
        if child:
            self.dfs(child, child.left, childDepth + 1, v, d)
            self.dfs(child, child.right, childDepth + 1, v, d)
