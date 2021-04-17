class Solution_3:
    def increasingTriplet(self, nums: List[int]) -> bool:
        # 下标 0 记录第一小的数字
        # 下标 1 记录第二小的数字
        res = [float('inf'), float('inf')]
        for num in nums:
            if num <= res[0]:
                # 先和第一小比
                res[0] = num
            elif num <= res[1]:
                # 再和第二小比
                res[1] = num
            elif num > res[1]:
                # 已经找到了一个三元递增子序列
                return True
        return False

# 参考之前账号提交记录
# 建议结合这篇题解理解思路（推荐）：https://leetcode-cn.com/problems/increasing-triplet-subsequence/solution/c-xian-xing-shi-jian-fu-za-du-xiang-xi-jie-xi-da-b/

