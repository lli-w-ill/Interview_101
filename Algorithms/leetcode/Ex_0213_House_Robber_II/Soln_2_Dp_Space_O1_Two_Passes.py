from typing import List

class Solution_2:
    def rob(self, nums: List[int]) -> int:
        # dp[i] 代表前 i 个房子在满足条件下能偷到的
        # 由于状态转移方程 dp[i] = max(dp[i-1], dp[i-2] + nums[i]) 只与 dp[i-1], dp[i-2] 有关系
        # 所以用 cur 表示 dp[i-1], pre 表示 dp[i-2]

        # 定义单排房间时的解法（Ex.198）
        def rob_undirectional(nums: List[int]) -> int:
            pre, cur = 0, 0
            for num in nums:
                temp = cur      # 记录更新 cur 前的值
                cur = max(cur, pre + num)
                pre = temp
            return cur
        
        # 将「环状排列房间」转换成「两个单排排列房间」
        # 对长度先进行特判
        length = len(nums) 
        if length == 0:
            return 0
        elif length == 1:
            return nums[0]
        
        no_rob_first_house = rob_undirectional(nums[1:])        # p1
        no_rob_last_house = rob_undirectional(nums[:length-1])  # p2
        return max(no_rob_first_house, no_rob_last_house)


# 参考题解（强烈推荐）：https://leetcode-cn.com/problems/house-robber-ii/solution/213-da-jia-jie-she-iidong-tai-gui-hua-jie-gou-hua-/
# 思路：将「环状排列房间」转换成「两个单排排列房间」(Ex.198)
#      即：在不偷第 1 个房子情况下（nums[1:]）能偷到的最大金额 p1
#         在不偷最后一个房子情况下（nums[:n-1]）能偷到的最大金额 p2
#      最终 max(p1, p2) 就是这道题的结果
# 设 N = len(nums)
# time complexity: O(N)
# space complxity: O(1)
