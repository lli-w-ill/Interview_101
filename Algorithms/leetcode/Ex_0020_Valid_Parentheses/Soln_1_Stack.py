class Solution_1:
    def isValid(self, s: str) -> bool:
        stack = []
        for ch in s:
            if ch == '(' or ch == '{' or ch == '[':
                stack.append(ch)
            elif ch == ')':
                if not stack or stack[-1] != '(':
                    return False
                else:
                    stack.pop()
            elif ch == ']':
                if not stack or stack[-1] != '[':
                    return False
                else:
                    stack.pop()
            elif ch == '}':
                if not stack or stack[-1] != '{':
                    return False
                else:
                    stack.pop()
            else:
                return False
        return len(stack) == 0
