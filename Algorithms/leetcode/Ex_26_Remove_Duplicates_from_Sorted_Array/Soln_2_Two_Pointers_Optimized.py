class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        # slow记录上一个不重复元素的值的下标
        # fast往后扫描
        slow, fast = 0, 1
        while fast < len(nums):
            if nums[slow] == nums[fast]:
                fast += 1
            else:
                nums[slow+1] = nums[fast]
                slow += 1
                fast += 1
        return slow + 1


# 参考：https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/x2gy9m/
# 优化的点在于：该解法不需要执行pop操作，所以不用移动list中的元素
