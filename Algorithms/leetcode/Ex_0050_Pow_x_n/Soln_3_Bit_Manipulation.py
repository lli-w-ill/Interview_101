class Solution_3:
    def myPow(self, x: float, n: int) -> float:
        if x == 0.0:
            return 0.0
        res = 1
        if n < 0:
            # x ^ (-10) = (1/x) ^ 10
            x = 1 / x
            n = -n
        
        while n > 0:
            if n & 1 == 1:
                res *= x
            x *= x
            n >>= 1
            print(x, n, res)

        return res

# 参考题解（非常推荐）：https://leetcode-cn.com/problems/powx-n/solution/50-powx-n-kuai-su-mi-qing-xi-tu-jie-by-jyd/
# 字节跳动面试题
