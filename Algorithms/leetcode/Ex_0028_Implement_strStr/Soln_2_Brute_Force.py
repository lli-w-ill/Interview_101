class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        return self.search(needle, haystack)

    def search(self, pat: str, txt: str) -> int:
        M = len(pat)
        N = len(txt)
        for i in range(N - M + 1):
            j = 0
            while j < M:
                if pat[j] != txt[i + j]:
                    break
                j += 1
            if j == M:
                return i
        return -1

# 参考题解（暴力解法）：https://leetcode-cn.com/problems/implement-strstr/solution/kmp-suan-fa-xiang-jie-by-labuladong/

