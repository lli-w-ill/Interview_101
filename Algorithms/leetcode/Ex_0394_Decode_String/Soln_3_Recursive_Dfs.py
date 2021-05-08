class Solution_3:
    def decodeString(self, s: str) -> str:
        def dfs(s: str, i: int) -> Tuple[str, int]:
            res, multi = "", ""
            while i < len(s):
                c = s[i]
                if c.isnumeric():
                    multi += c
                elif c.isalpha():
                    res += c
                elif c == '[':
                    innerRes, i = dfs(s, i+1)
                    res += innerRes * int(multi)
                    multi = ""
                elif c == ']':
                    break
                i += 1
            return res, i
        return dfs(s, 0)[0]


# 参考：https://leetcode-cn.com/problems/decode-string/solution/decode-string-fu-zhu-zhan-fa-di-gui-fa-by-jyd/
