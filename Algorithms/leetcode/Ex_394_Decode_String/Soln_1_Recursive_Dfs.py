class Solution:
    def decodeString(self, s: str) -> str:
        if not s:
            return ""
        return self.recur(s, 0, 1)[0]

    def recur(self, s: str, idx: int, repeatTime: int) -> Tuple[str, int]:
        ans = ""
        while idx < len(s):
            if s[idx].isnumeric():
                # 注意数字可能是多位数字以上
                num = ""
                while idx < len(s) and s[idx].isnumeric():
                    num += s[idx]
                    idx += 1
                string, nextIdx = self.recur(s, idx, int(num))
                ans += string
                idx = nextIdx - 1   # 这里-1是为了抵消循环最后idx+=1的效果
            elif s[idx] == '[':
                pass
            elif s[idx] == ']':
                ans = ans * repeatTime
                return ans, idx + 1
            elif s[idx].isalpha():
                ans += s[idx]
            idx += 1
        return ans, idx
