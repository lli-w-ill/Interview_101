# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution_2:
    def recoverTree(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        firstNode = None
        secondNode = None
        pre = None

        stack = []
        cur = root

        while stack or cur:
            while cur:
                stack.append(cur)
                cur = cur.left
            cur = stack.pop()

            # 如果「第一个节点」还没有找到，那么我们要找「前一个节点的值大于后一个节点的值的“前一个节点”」
            if firstNode is None and pre and pre.val > cur.val:
                firstNode = pre
            # 如果「第一个节点」已经找到了，那么我们要找「前一个节点的值大于后一个节点的值的“后一个节点”」
            if firstNode is not None and pre.val > cur.val:
                secondNode = cur
            # 注意：上面两个 if 采用的是「并列关系」而非「if-else」关系，这样就可以检测到相邻元素错位的情况了，在遇到不相邻错位时，secondNode虽然会先指向一个不是『第二个节点』的节点，但是随着往后继续循环，一定会被正确的『第二个节点』覆盖掉（详见参考题解下 @LittleWave 评论下 @import-yuefeng 的解答，建议在纸上跟着画一遍例子中给的 [1,3,null,null,2] 过程）
            
            pre = cur
            cur = cur.right

        print(firstNode.val)
        print(secondNode.val)

        # 交换两个节点的值即可
        firstNode.val, secondNode.val = secondNode.val, firstNode.val

# 参考题解（推荐）：https://leetcode-cn.com/problems/recover-binary-search-tree/solution/zhong-xu-bian-li-by-powcai/
# 设一共有 N 个 nodes
# 时间复杂度：O(N)
# 空间复杂度：O(N)
