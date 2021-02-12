class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        k %= len(nums)
        if k == 0 or len(nums) <= 1:
            return
        temp = nums[0]
        i = k
        cnt = 0
        count = 0
        while cnt < len(nums):
            nums[i], temp = temp, nums[i]
            if i == count:
                count += 1
                i = count % len(nums)
                temp = nums[i]
            i = (i + k) % len(nums)
            cnt += 1


# 参考：https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/x2skh7/?discussion=iInPDl
