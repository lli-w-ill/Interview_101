class Solution_1:
    def canPartition(self, nums: List[int]) -> bool:
        if not nums or len(nums) <= 1:
            return False
        ssum = sum(nums)
        if ssum % 2 != 0:
            return False

        subsetSum = ssum // 2
        # dp[i] = True 表示当前有子串的和为 i
        # 第一个元素为 True 因为空串的和为 0
        dp = [True] + [False] * subsetSum

        for num in nums:
            for j in range(subsetSum, num-1, -1):  # 这里一定要倒着访问
                dp[j] = dp[j] or dp[j-num]

        return dp[subsetSum]

# 思路：在 nums 中找到一个子串和为 subsetSum 的子串，即返回 True