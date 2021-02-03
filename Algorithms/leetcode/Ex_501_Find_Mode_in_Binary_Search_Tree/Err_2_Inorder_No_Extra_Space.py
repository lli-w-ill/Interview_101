# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findMode(self, root: TreeNode) -> List[int]:
        if not root:
            return []

        maxCount = 0
        count = 0
        modes = []  # 存放所有众数

        def inorder(cur: TreeNode, pre: TreeNode) -> None:
            nonlocal count, maxCount, modes
            if cur.left:
                # 先访问左子树
                inorder(cur.left, cur)

            # 访问当前节点
            if not pre:  # 第一个节点(root)，开始计数
                count = 1
            elif pre.val == cur.val:
                count += 1
            else:
                count = 1   # 遇到新的数字了

            if count == maxCount:
                modes.append(cur.val)

            if count > maxCount:
                maxCount = count

                # 清空modes，因为之前的modes不再是众数了，然后将cur.val加入到结果集里
                modes.clear()
                modes.append(cur.val)
                # 更新maxCount

            if cur.right:
                # 访问右子树
                inorder(cur.right, cur)
        inorder(root, None)
        return modes


# 相对于Soln_3，这里的错点在于：当把pre当作参数传给inorder方法时，pre不再是全局变量了，这其中有微妙的差别，可以对比Soln_3

# 参考：https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/solution/501-er-cha-sou-suo-shu-zhong-de-zhong-shu-bao-li-t/
