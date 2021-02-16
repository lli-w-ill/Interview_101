class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        length = len(nums)
        if not length or length < 3:
            return []
        nums.sort()
        res = []
        for i in range(length):
            if nums[i] > 0:
                # 因为数组是升序的，如果第一个数已经大于0了，那么三个数的和比大于零
                return res
            if i > 0 and nums[i] == nums[i-1]:
                continue    # 总是让i指向nums中相同数字的最后那个数字
            left = i + 1   # 左边界
            right = length - 1  # 右边界
            while left < right:
                ssum = nums[i] + nums[left] + nums[right]
                if ssum == 0:
                    res.append([nums[i], nums[left], nums[right]])
                    # 将left移动到下一个不同的数字的下标
                    while left < right and nums[left] == nums[left+1]:
                        left += 1
                    left += 1
                    # 将right移动到前一个不同数字的下标
                    while right > left and nums[right] == nums[right-1]:
                        right -= 1
                    right -= 1
                elif ssum > 0:
                    right -= 1
                else:
                    left += 1
        return res
