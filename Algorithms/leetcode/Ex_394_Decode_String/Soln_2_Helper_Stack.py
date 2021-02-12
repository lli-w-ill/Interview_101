class Solution:
    def decodeString(self, s: str) -> str:
        if not s:
            return ""
        stack = []  # 辅助栈
        multi = ""
        res = ""
        for c in s:
            if c.isnumeric():
                multi += c
            elif c.isalpha():
                res += c
            elif c == '[':
                stack.append((int(multi), res))
                multi = ""
                res = ""
            elif c == ']':
                cur_multi, last_res = stack.pop()
                res = last_res + res * cur_multi
        return res


# 参考：https://leetcode-cn.com/problems/decode-string/solution/decode-string-fu-zhu-zhan-fa-di-gui-fa-by-jyd/
