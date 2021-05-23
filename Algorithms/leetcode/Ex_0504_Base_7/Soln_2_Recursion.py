class Solution_2:
    @lru_cache
    def convertToBase7(self, num: int) -> str:
        if num < 0:
            return "-" + self.convertToBase7(-num);
        
        # base case
        if num < 7:
            return str(num)
        
        # recursion
        return self.convertToBase7(num // 7) + str(num % 7)


# 参考题解（非常推荐）：https://leetcode-cn.com/problems/base-7/solution/li-kou-jia-jia-jin-zhi-zhuan-hua-wen-ti-33xjw/
