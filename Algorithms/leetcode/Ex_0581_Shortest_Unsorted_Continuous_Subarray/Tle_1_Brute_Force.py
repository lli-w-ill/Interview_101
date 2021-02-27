class Tle_1:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        sortedNums = sorted(nums, reverse=False)
        if nums == sortedNums:
            return 0
        for ws in range(2, len(nums) + 1):  # window size
            for start in range(0, len(nums) - ws + 1):
                end = start + ws
                if nums[:start] + sorted(nums[start:end]) + nums[end:] == sortedNums:
                    # print(nums[start:end])
                    return ws
