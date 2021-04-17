class Tle_2:
    def increasingTriplet(self, nums: List[int]) -> bool:
        length = len(nums)
        if len(set(nums)) < 3:
            return False
        
        # 定义三个数的下标
        firstIdx, secondIdx, thirdIdx = 0, -1, -1

        # 定义两个备份，记录上一个第二个数的坐标第一次更新之前的值和上一个第三个数的坐标第一次更新之前的值，以用于快速更新第一个数下次的坐标和第二个数下次的坐标
        prev_thirdIdx = thirdIdx
        prev_secondIdx = secondIdx

        while firstIdx < length - 2:
            # 初始化 secondIdx 为下一个与 nums[firstIdx] 不同的数的下标
            secondIdx = firstIdx
            while secondIdx < length - 1 and nums[secondIdx] == nums[firstIdx]:
                secondIdx += 1
            firstUpdate_secondIdx = True

            while secondIdx < length - 1:
                # 初始化 thirdIdx 为下一个与 nums[secondIdx] 不同的数的下标
                thirdIdx = secondIdx
                while thirdIdx < length and nums[thirdIdx] == nums[secondIdx]:
                    thirdIdx += 1
                firstUpdate_thirdIdx = True

                while thirdIdx < length:
                    if nums[firstIdx] < nums[secondIdx] < nums[thirdIdx]:
                        return True
                    
                    # 更新第三个数下次的坐标
                    # 首先备份，以用于更新 secondIdx
                    if firstUpdate_thirdIdx:
                        prev_thirdIdx = thirdIdx
                        firstUpdate_thirdIdx = False
                    curr_thirdIdx = thirdIdx
                    # 更新
                    while thirdIdx < length and nums[thirdIdx] == nums[curr_thirdIdx]:
                        thirdIdx += 1

                if firstUpdate_thirdIdx is True:
                    # 说明内层循环没有更新过，表明当前 secondIdx 已经指向了最后一个 distinct number
                    return False
                # 首先备份，更新第二个数下次的坐标，直接更新为第三个数上一次的坐标即可
                if firstUpdate_secondIdx:
                    prev_secondIdx = secondIdx
                    firstUpdate_secondIdx = False
                secondIdx = prev_thirdIdx
            
            if firstUpdate_secondIdx is True:
                # 说明内层循环没有更新过，表明当前 firstIdx 已经指向了最后一个 distinct number
                return False
            # 更新第一个数下次的坐标，直接更新为第二个数上一次的坐标即可
            firstIdx = prev_secondIdx
                    
        return False

# 思路：优化 Soln_1 中的解法，每次将 firstIdx, secondIdx, thirdIdx 更新到和当前不同的下一个数，从而减少内层循环
# 74 / 75 个通过测试用例

