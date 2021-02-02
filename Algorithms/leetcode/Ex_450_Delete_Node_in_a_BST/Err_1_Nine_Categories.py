# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        if not root:
            return root
        # 第一步：首先找到要删的节点
        curr = root
        parent = TreeNode(10000000000000)
        parent.left = root
        while curr and curr.val != key:
            parent = curr
            if curr.val > key:
                curr = curr.left
            else:
                curr = curr.right
        # 现在curr指向要删的节点
        # 删除分9种情况：
        #   第零种情况：curr不存在
        #   第一种情况：curr是叶子结点
        #   第二种情况：curr只有左子树
        #   第三种情况：curr只有右子树
        #   第四种情况：curr有左右子树，但是左孩子只有左子树
        #   第五种情况：curr有左右子树，但是左孩子只有右子树
        #   第六种情况：curr有左右子树，但是右孩子只有左子树
        #   第七种情况：curr有左右子树，但是右孩子只有右子树
        #   第八种情况：curr有左右子树，而且左右孩子都有左右子树
        if not curr:
            return root    # 0
        elif not curr.left and not curr.right:    # 1
            print(1)
            if curr == root:
                return None
            if curr == parent.left:
                parent.left = None
            else:
                parent.right = None
        elif not curr.right:  # 2
            print(2)
            curr.val = curr.left.val
            curr.left = curr.left.left
        elif not curr.left:   # 3
            print(3)
            curr.val = curr.right.val
            curr.right = curr.right.right
        elif not curr.left.right:   # 4
            print(4)
            curr.val = curr.left.val
            curr.left = curr.left.left
        elif not curr.left.left:    # 5
            print(5)
            # 需要把curr.left.right挂在curr右子树的最左节点的左孩子
            target = curr.right
            while target.left:
                target = target.left
            target.left = curr.left.right
            curr.left.right = None
            curr.val = curr.left.val
            curr.left = None
        elif not curr.right.right:  # 6
            print(6)
            # 需要把curr.right.left挂在curr左子树的最右节点的右孩子
            target = curr.left
            while target.right:
                target = target.right
            target.right = curr.right.left
            curr.right.left = None
            curr.val = curr.right.val
            curr.right = None
        elif not curr.right.left:   # 7
            print(7)
            curr.val = curr.right.val
            curr.right = curr.right.right
        else:   # 8
            print(8)
            # 可以用5的想法，也可以用6的想法
            # 这里采用5的想法
            target = curr.right
            while target.left:
                target = target.left
            target.left = curr.left.right
            curr.left.right = None
            curr.val = curr.left.val
            curr.left = curr.left.left
        return root

# 测试用例 87 / 91
# 卡在了测试用例：
# [8,0,31,null,6,28,45,1,7,25,30,32,49,null,4,null,null,9,26,29,null,null,42,47,null,2,5,null,12,null,27,null,null,41,43,46,48,null,3,null,null,10,19,null,null,33,null,null,44,null,null,null,null,null,null,null,11,18,20,null,37,null,null,null,null,14,null,null,22,36,38,13,15,21,24,34,null,null,39,null,null,null,16,null,null,23,null,null,35,null,40,null,17]
# 1
# 预期结果：[8,0,31,null,6,28,45,2,7,25,30,32,49,null,4,null,null,9,26,29,null,null,42,47,null,3,5,null,12,null,27,null,null,41,43,46,48,null,null,null,null,10,19,null,null,33,null,null,44,null,null,null,null,null,11,18,20,null,37,null,null,null,null,14,null,null,22,36,38,13,15,21,24,34,null,null,39,null,null,null,16,null,null,23,null,null,35,null,40,null,17]
# 我的输出：[8,0,31,null,6,28,45,4,7,25,30,32,49,null,5,null,null,9,26,29,null,null,42,47,null,null,null,null,12,null,27,null,null,41,43,46,48,10,19,null,null,33,null,null,44,null,null,null,null,null,11,18,20,null,37,null,null,null,null,14,null,null,22,36,38,13,15,21,24,34,null,null,39,null,null,null,16,null,null,23,null,null,35,null,40,null,17]
