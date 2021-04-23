# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


from collections import deque

class MyTreeNode:
    def __init__(self, node: TreeNode, start: int, end: int, index: int):
        self.node = node

        # start, end 用于模拟递归时计算 mid 的下标，从而计算左／右子树中的下标范围，相当于 Soln_2 递归方法中 sortedArrayRangeToBST 的参数 start, end
        self.start = start
        self.end = end

        # 当前 node.val 在 nums 中的下标
        self.index = index

class Solution_4:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        queue = deque()
        # [start, end) 左包含，右不包含
        start = 0
        end = len(nums)
        if start == end:
            # nums 为空
            return None
        
        # 先让一个未赋值的根节点入队
        root = TreeNode(-1)
        queue.append(MyTreeNode(root, start, end, (start + end) >> 1))

        # end - start 表示当前树可用的数字的个数
        while queue:
            # 给当前节点赋值
            curNode = queue.popleft()
            start, end, mid = curNode.start, curNode.end, curNode.index
            cur = curNode.node
            cur.val = nums[mid]

            # 考虑左子树
            if start < mid:
                # 先创建一个未赋值的左根节点，入队
                cur.left = TreeNode(-1)
                queue.append(MyTreeNode(cur.left, start, mid, (start + mid) >> 1))
            # 考虑右子树
            if mid + 1 < end:
                # 先创建一个未赋值的右根节点，入队
                cur.right = TreeNode(-1)
                queue.append(MyTreeNode(cur.right, mid + 1, end, (mid + 1 + end) >> 1))

        return root
            

# 参考题解（非常推荐）：https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-24/
