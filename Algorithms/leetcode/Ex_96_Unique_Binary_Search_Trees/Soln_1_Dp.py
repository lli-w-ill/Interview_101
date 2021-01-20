class Solution:
    def numTrees(self, n: int) -> int:
        dp = [0] * (n + 1)
        dp[0] = 1   # None as root
        dp[1] = 1   # 1 as root
        for i in range(2, n+1):
            for j in range(1, i+1):
                # G(n) = f(1) + f(2) + ... + f(n)
                # f(i) = G(i-1) * G(n-i)
                # ==> G(n) = G(0)*G(n-1) + G(1)*G(n-2) + ... + G(n-2)*G(1) + G(n-1)*G(0)
                dp[i] += dp[j-1] * dp[i-j]
        return dp[-1]


# 参考：https://leetcode-cn.com/problems/unique-binary-search-trees/solution/hua-jie-suan-fa-96-bu-tong-de-er-cha-sou-suo-shu-b/
