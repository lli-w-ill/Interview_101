# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        prefixSumCount = {0: 1}
        return self.helper(root, prefixSumCount, sum, 0)

    def helper(self, node: TreeNode, prefixSumCount: Dict[int, int], target: int, curSum: int) -> int:
        if not node:
            return 0

        # 从root到当前节点node的path sum
        curSum += node.val
        # 如果从root到中间的某个节点 X 路径之和有等于curSum-target的，那么从那个节点 X 到现在的当前节点 node 之间的路径和就为 curSum - (curSum - target) = target
        count = 0
        if prefixSumCount.get(curSum - target, 0) > 0:
            count += prefixSumCount[curSum-target]
        # 更新路径和字典
        prefixSumCount[curSum] = prefixSumCount.get(curSum, 0) + 1
        # 进入下一层，继续往下找
        count += self.helper(node.left, prefixSumCount, target, curSum)
        count += self.helper(node.right, prefixSumCount, target, curSum)
        # 在返回上一层之前，要恢复本层累加的prefixSumCount
        prefixSumCount[curSum] -= 1
        return count


# 参考：https://leetcode-cn.com/problems/path-sum-iii/solution/qian-zhui-he-di-gui-hui-su-by-shi-huo-de-xia-tian/
