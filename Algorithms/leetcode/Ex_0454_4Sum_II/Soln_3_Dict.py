from collections import defaultdict

class Solution_3:
    def fourSumCount(self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]) -> int:
        # 计算 nums1, nums2 中所有可能二元组和的频率
        sum12 = defaultdict(int)
        for i in range(len(nums1)):
            for j in range(len(nums2)):
                sum12[nums1[i] + nums2[j]] += 1
        
        res = 0
        for k in range(len(nums3)):
            for l in range(len(nums4)):
                res += sum12[-(nums3[k] + nums4[l])]
        
        return res

# 参考题解：https://leetcode-cn.com/problems/4sum-ii/solution/chao-ji-rong-yi-li-jie-de-fang-fa-si-shu-xiang-jia/
