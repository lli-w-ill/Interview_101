class Solution_3:
    def findPeakElement(self, nums: List[int]) -> int:
        l = 0
        r = len(nums) - 1
        while l < r:
            mid = l + (r - l) // 2
            if nums[mid] > nums[mid+1]:
                r = mid
            elif nums[mid] < nums[mid+1]:
                # 大的一侧肯定有峰值
                l = mid + 1
        return l


# 参考题解：https://leetcode-cn.com/problems/find-peak-element/solution/hua-jie-suan-fa-162-xun-zhao-feng-zhi-by-guanpengc/
