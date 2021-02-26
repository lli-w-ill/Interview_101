class Solution_1:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0
        if len(nums) == 1:
            return 1
        slow, fast = 0, 1
        while fast < len(nums):
            if nums[slow] == nums[fast]:
                nums.pop(fast)
            else:
                slow = fast
                fast += 1
        return len(nums)
