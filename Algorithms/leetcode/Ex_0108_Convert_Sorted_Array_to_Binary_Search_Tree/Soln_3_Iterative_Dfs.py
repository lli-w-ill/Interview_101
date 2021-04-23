# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class MyTreeNode:
    def __init__(self, node: TreeNode, start: int, end: int, index: int):
        self.node = node

        # start, end 用于模拟递归时计算 mid 的下标，从而计算左／右子树中的下标范围，相当于 Soln_2 递归方法中 sortedArrayRangeToBST 的参数 start, end
        self.start = start
        self.end = end

        # 当前 node.val 在 nums 中的下标
        self.index = index

class Solution_3:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        stack = []
        # [start, end) 左包含，右不包含
        start = 0
        end = len(nums)
        if start == end:
            # nums 为空
            return None     

        # 压入根结点
        mid = (start + end) >> 1
        root = TreeNode(nums[mid])
        stack.append(MyTreeNode(root, start, end, mid))
        cur = root

        # end - start 表示当前树可用的数字的个数
        while end - start > 1 or stack:
            # 考虑左子树
            while end - start > 1:
                mid = (start + end) >> 1        # 当前根节点
                end = mid       # 更新 end（右不包含，所以不是 mid-1）
                mid = (start + end) >> 1        # 左子树的中点
                # 生成左子树的根节点，并与父节点相连
                leftRoot = TreeNode(nums[mid])
                cur.left = leftRoot
        
                # 将左子树的根节点压入栈中
                stack.append(MyTreeNode(leftRoot, start, end, mid))
                # 将 cur 更新为左子树根节点
                cur = leftRoot

            # 考虑右子树
            myNode = stack.pop()    # 当前根节点
            start, end = myNode.start, myNode.end   # 左子树 + 根节点 + 右子树的下标范围
            mid = myNode.index    # [start, mid) 是左子树的数字, mid 是根节点的, (mid, end) 是右子树的
            cur = myNode.node
            start = mid + 1     # 更新到右子树的下标
            if end - start > 0:
                # 如果还有数字留给右子树，则创建右子树根节点
                mid = (start + end) >> 1
                rightRoot = TreeNode(nums[mid])
                cur.right = rightRoot

                # 将右子树的根节点压入栈中
                stack.append(MyTreeNode(rightRoot, start, end, mid))
                # 将 cur 更新为右子树根节点
                cur = cur.right
        
        return root
            

# 参考题解（非常推荐）：https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-24/

