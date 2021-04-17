class Tle_10:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        k %= len(nums)
        for i in range(k):
            last = nums[-1]
            # 旋转一次：倒数第二个元素～第一个元素往后错一位
            for j in range(len(nums)-1, 0, -1):
                nums[j] = nums[j-1]
            # 第一个元素设为原先的最后一个元素
            nums[0] = last
