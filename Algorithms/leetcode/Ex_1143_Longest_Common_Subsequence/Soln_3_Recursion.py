class Solution_3:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        @lru_cache(None)
        def dfs(i, j):
            if not i or not j:
                return 0
            if text1[i-1] == text2[j-1]:
                return dfs(i-1, j-1) + 1
            return max(dfs(i-1, j), dfs(i, j-1))
        
        return dfs(len(text1), len(text2))

# 参考题解：https://leetcode-cn.com/problems/longest-common-subsequence/solution/fu-xue-ming-zhu-er-wei-dong-tai-gui-hua-r5ez6/
