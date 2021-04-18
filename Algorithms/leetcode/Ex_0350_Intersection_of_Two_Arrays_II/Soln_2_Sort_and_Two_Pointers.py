class Solution_2:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort();
        nums2.sort();

        length1 = len(nums1)
        length2 = len(nums2)
        i1 = 0
        i2 = 0
        res = []
        while i1 < length1 and i2 < length2:
            if nums1[i1] == nums2[i2]:
                res.append(nums1[i1])
                i1 += 1
                i2 += 1
            elif nums1[i1] > nums2[i2]:
                # i2 落后了
                i2 += 1
            elif nums1[i1] < nums2[i2]:
                # i1 落后了
                i1 += 1
        return res

# 如果给定的数组已经排好序，这种方法适用

