class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        # C^{m-1}_{m+n-2}
        return int(math.factorial(m+n-2) / (math.factorial(m-1) * math.factorial(n-1)))

# 参考：https://leetcode-cn.com/problems/unique-paths/solution/dong-tai-gui-hua-by-powcai-2/
# 复习公式：
# C^{m}_{n} = (m + n)! / (m! * n!)
# A^{m}_{n} 或者 P^{m}_{n} = n! / (n - m)!
