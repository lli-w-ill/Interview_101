# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root: TreeNode) -> str:
        """Encodes a tree to a single string.
        序列化规则：
        每个node之间会用逗号分割，每个节点将用value|parentIndex的形式表达
        如果root node没有parentIndex，则认为-1，root node的Index设为1
        例如：  2   
             /   \     => 2|1,1|1,3|1
            1     3
        至于是node相对于parentIndex是左孩子还是右孩子，可以通过比较value来区分（利用二叉搜索树的特性）
        """
        if not root:
            return ""
        rootIndex = 1
        string = str(root.val) + '|' + '-1'

        def dfs(node: TreeNode, currIndex: int, parentIndex: int) -> None:
            nonlocal string
            string += ',' + str(node.val) + '|' + str(parentIndex)
            if node.left:
                dfs(node.left, currIndex*2, currIndex)
            if node.right:
                dfs(node.right, currIndex*2+1, currIndex)
        if root.left:
            dfs(root.left, rootIndex*2, rootIndex)
        if root.right:
            dfs(root.right, rootIndex*2+1, rootIndex)
        return string

    def deserialize(self, data: str) -> TreeNode:
        """Decodes your encoded data to tree.
        """
        if not data or len(data) == 0:
            return None
        li = data.split(',')
        # 构建root节点
        # key: node index
        # value: TreeNode
        index2node = {}
        rootIndex = 1
        rootVal, _ = [int(s) for s in li[0].split('|')]  # 不要忘了转换类型
        index2node[rootIndex] = TreeNode(rootVal)
        for l in li[1:]:
            nodeVal, parentIndex = [int(s) for s in l.split('|')]
            if nodeVal < index2node[parentIndex].val:
                # 说明是parent node的左孩子
                index2node[parentIndex*2] = TreeNode(nodeVal)
                index2node[parentIndex].left = index2node[parentIndex*2]
            else:
                # 说明是parent node的右孩子
                index2node[parentIndex*2+1] = TreeNode(nodeVal)
                index2node[parentIndex].right = index2node[parentIndex*2+1]
        return index2node[rootIndex]


# Your Codec object will be instantiated and called as such:
# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# tree = ser.serialize(root)
# ans = deser.deserialize(tree)
# return ans
