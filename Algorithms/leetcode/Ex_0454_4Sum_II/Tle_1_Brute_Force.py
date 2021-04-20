class Tle_1:
    def fourSumCount(self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]) -> int:
        res = 0
        for i in range(len(nums1)):
            for j in range(len(nums2)):
                for k in range(len(nums3)):
                    for l in range(len(nums4)):
                        if sum([nums1[i], nums2[j], nums3[k], nums4[l]]) == 0:
                            res += 1
        return res
