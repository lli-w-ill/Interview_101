class Solution_2:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        res = []
        nthBit = 1 << n
        for i in range(2**n):
            # 生成bit mask，从000...0到111...1
            # bin() is an in-built function in Python that takes in integer x and returns the binary representation of x in a string format.
            bitmask = bin(i | nthBit)[3:]   # Q：为什么是[3:]？（很久之前写的解法忘了。。。）
            res.append([nums[j] for j in range(n) if bitmask[j] == '1'])
        return res
