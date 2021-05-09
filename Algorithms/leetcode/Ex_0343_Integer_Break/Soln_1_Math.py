import math

class Solution_1:
    def integerBreak(self, n: int) -> int:
        if n <= 3:
            return n - 1
    
        a, b = n // 3, n % 3
        
        if b == 0:
            return int(math.pow(3, a))
        if b == 1:
            return int(math.pow(3, a - 1) * 4)
        
        return int(math.pow(3, a) * 2)

# 参考题解：https://leetcode-cn.com/problems/integer-break/solution/343-zheng-shu-chai-fen-tan-xin-by-jyd/
