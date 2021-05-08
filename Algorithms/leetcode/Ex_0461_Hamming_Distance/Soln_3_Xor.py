class Solution_3:
    def hammingDistance(self, x: int, y: int) -> int:
        return bin(x ^ y).count('1')

# 参考题解：https://leetcode-cn.com/problems/hamming-distance/solution/yi-ming-ju-chi-by-leetcode/
