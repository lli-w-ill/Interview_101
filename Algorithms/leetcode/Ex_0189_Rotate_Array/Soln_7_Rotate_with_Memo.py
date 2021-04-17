class Solution_7:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        k %= len(nums)
        # 保存前len-k个元素
        temp = nums[:len(nums)-k]
        # 更新前k个元素
        nums[:k] = nums[len(nums)-k:]
        # 更新后len-k个元素
        nums[k:] = temp
