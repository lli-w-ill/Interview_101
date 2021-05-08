class Solution_11:
    def rob(self, nums: List[int]) -> int:
        # dp[i] 代表前 i 个房子在满足条件下能偷到的
        # 由于状态转移方程 dp[i] = max(dp[i-1], dp[i-2] + nums[i]) 只与 dp[i-1], dp[i-2] 有关系
        # 所以用 cur 表示 dp[i-1], pre 表示 dp[i-2]
        pre, cur = 0, 0     # 初始时 pre 代表前 -1 个房间能偷到的最大收益，cur 代表前 0 个房间能偷到的最大收益
        for num in nums:
            temp = cur      # 记录更新前的 cur
            cur = max(cur, pre + num)
            pre = temp
        return cur


# 参考题解（强烈推荐）：https://leetcode-cn.com/problems/house-robber/solution/da-jia-jie-she-dong-tai-gui-hua-jie-gou-hua-si-lu-/
# 设 N = len(nums)
# time complexity: O(N)
# space complexity: O(1)
