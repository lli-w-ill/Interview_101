class Solution_1:
    def getSum(self, a: int, b: int) -> int:
        MASK = 0x100000000      # 2^32
        INT_MAX = 0x7FFFFFFF
        INT_MIN = INT_MAX + 1

        while b != 0:
            # 计算进位
            carry = (a & b) << 1    # (a & b) << 1 是「仅计算」进位相加后的结果
            # 取余保证结果在 [0, 2^31-1] 范围内
            a = (a ^ b) % MASK  # (a ^ b) 是不进位的加法结果
            b = carry % MASK    # 用 b 当作
        
        if a <= INT_MAX:
            # 结果是正数或零
            return a
        else:
            # 结果是负数
            # return ~((a % INT_MIN) ^ INT_MAX)
            return ~(a ^ 0xFFFFFFFF)


# 参考题解（非常推荐）：https://leetcode-cn.com/problems/sum-of-two-integers/solution/wei-yun-suan-xiang-jie-yi-ji-zai-python-zhong-xu-y/
# 最后一行 return 参考题解下方 @loick 的热评和其下面的回复
# 
# 举例：a = (1010), b = (0110)
# 下面执行 while 的每次循环结果:
#   #   carry     a       b
#   1   (0100)  (1100)  (0100)
#   2   (1000)  (1000)  (1000)
#   3  (10000)  (0000) (10000)
#   4  (00000) (10000) (00000)  END
