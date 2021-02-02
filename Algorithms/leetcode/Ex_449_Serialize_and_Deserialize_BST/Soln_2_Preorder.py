# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root: TreeNode) -> str:
        """Encodes a tree to a single string.
        序列化规则：先序遍历
        """
        if not root:
            return '# '    # 别忘了#好后面需要加一个空格，因为deserilize是需要以空格split
        return str(root.val) + ' ' + self.serialize(root.left) + self.serialize(root.right)

    def deserialize(self, data: str) -> TreeNode:
        """Decodes your encoded data to tree.
        """
        if data == '# ':
            return None
        preorder = data.split()
        index = 0

        def rebuild() -> TreeNode:
            nonlocal index
            if preorder[index] == '#':
                return None
            node = TreeNode(int(preorder[index]))   # 别忘了类型转换str->int
            index += 1
            node.left = rebuild()
            index += 1
            node.right = rebuild()
            return node
        return rebuild()


# 参考：https://leetcode-cn.com/problems/serialize-and-deserialize-bst/solution/cqian-xu-bian-li-ji-zhi-you-ya-di-di-gui-shi-xian-/

# Your Codec object will be instantiated and called as such:
# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# tree = ser.serialize(root)
# ans = deser.deserialize(tree)
# return ans
