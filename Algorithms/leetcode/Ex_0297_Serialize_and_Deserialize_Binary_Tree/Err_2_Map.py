# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Err_2:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        if root is None:
            return ""

        def dfs(node: TreeNode, tag: int) -> str:
            if node is None:
                return ""
            leftStr= dfs(node.left, tag * 2)
            curStr = str(tag) + "|" + str(node.val)
            rightStr = dfs(node.right, tag * 2 + 1)

            resStr = ""
            if leftStr:
                resStr = leftStr + ","
            resStr += curStr
            if rightStr:
                resStr += "," + rightStr
            
            return resStr

        tag = 1
        return dfs(root, tag)
        
    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        if len(data) == 0:
            return None
        mmap = {}
        for s in data.split(','):
            tag, nodeVal = s.split('|')
            mmap[int(tag)] = TreeNode(nodeVal)

        # 连接左右孩子
        for tag in mmap.keys():
            print(tag)
            if (tag & 1) == 0 and (tag / 2) in mmap:
                mmap[tag/2].left = mmap[tag]
            if (tag & 1) == 1 and ((tag - 1) / 2) in mmap:
                mmap[(tag-1) / 2].right = mmap[tag]
        
        return mmap[1]
        
    

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))

# 可以跑这个程序看到最后key有多大！
