class Tle_1:
    def increasingTriplet(self, nums: List[int]) -> bool:
        length = len(nums)
        if length < 3:
            return False
        
        # 定义三个数的下标
        firstIdx, secondIdx, thirdIdx = 0, 1, 2

        for firstIdx in range(length - 2):
            for secondIdx in range(firstIdx + 1, length - 1):
                for thirdIdx in range(secondIdx + 1, length):
                    if nums[firstIdx] < nums[secondIdx] < nums[thirdIdx]:
                        return True
        return False

# 32 / 75 个通过测试用例

