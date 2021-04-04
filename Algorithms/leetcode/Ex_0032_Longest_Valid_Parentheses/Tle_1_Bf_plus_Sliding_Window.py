class Solution:
    def longestValidParentheses(self, s: str) -> int:
        for ws in range(len(s), -1, -1):
            for i in range(0, len(s) - ws + 1):
                if self.checkValidity(s[i:i+ws]):
                    return ws
        return 0

    def checkValidity(self, s: str) -> bool:
        leftUsed = 0    # 左括号使用个数
        rightUsed = 0   # 右括号使用个数
        for i in range(len(s)):
            if (rightUsed > leftUsed):
                return False
            if (s[i] == '('):
                leftUsed += 1
            elif (s[i] == ')'):
                rightUsed += 1
        return leftUsed == rightUsed
