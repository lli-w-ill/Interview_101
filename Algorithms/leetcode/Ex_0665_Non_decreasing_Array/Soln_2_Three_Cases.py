class Solution_2:
    def checkPossibility(self, nums: List[int]) -> bool:
        length = len(nums)
        count = 0   # 记录需要修改数字的次数

        for i in range(1, length):
            if nums[i-1] > nums[i]:
                # 出现逆序
                if i == 1:
                    # 修改 nums[i-1]（也可以修改 nums[i]，但是因为不知道 i 之后的数字是什么，所以最好不要动 nums[i]）
                    nums[i-1] = nums[i]
                elif i > 1 and nums[i] >= nums[i-2]:
                    # 理由同 i==1
                    nums[i-1] = nums[i]
                elif i > 1 and nums[i] < nums[i-2]:
                    # 不得不修改 nums[i]
                    nums[i] = nums[i-1]
                count += 1
        
        return count <= 1

# 参考题解（推荐）：https://leetcode-cn.com/problems/non-decreasing-array/solution/3-zhang-dong-tu-bang-zhu-ni-li-jie-zhe-d-06gi/
