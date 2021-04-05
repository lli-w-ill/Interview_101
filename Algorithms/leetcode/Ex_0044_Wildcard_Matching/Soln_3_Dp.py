class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        rows = len(p) + 1
        cols = len(s) + 1
        # dp[i][j] = True 表示 s[0...i] 与 p[0...j] 匹配
        dp = [[False] * cols for _ in range(rows)]

        # base case
        dp[0][0] = True
        if p.startswith('*'):
            dp[1][:] = [True] * cols
        
        for k in range(len(p)):
            if p[k] == '*':
                dp[k+1][:] = [True] * cols
            else:
                break
        
        for c in range(1, cols):
            for r in range(1, rows):
                if p[r-1] == s[c-1] or p[r-1] == '?':
                    dp[r][c] = dp[r-1][c-1]
                elif p[r-1] == '*' and dp[r-1][c]:
                    dp[r][c:] = [True] * (cols - c)
        
        return dp[-1][-1]
    
# 参考题解（非常推荐）：https://leetcode-cn.com/problems/wildcard-matching/solution/yi-ge-qi-pan-kan-dong-dong-tai-gui-hua-dpsi-lu-by-/
