class Solution_3:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = [[]]
        for num in nums: 
            # 每次让当前数字 num 与 res 中所有的子集组合，就构成了新的子集
            res += [curr + [num] for curr in res]
        return res
