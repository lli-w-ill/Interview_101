class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        if n == 0:
            return []
        res = []

        def generate(left: int, right: int, s: str) -> None:
            # base case
            if left == 0 and right == 0:
                res.append(s)
                return
            if right == left:
                # 如果右括号已经“抵消”了所有左括号，那么只能加左括号
                if left > 0:
                    generate(left - 1, right, s + '(')
            else:
                if left > 0:
                    generate(left - 1, right, s + '(')
                if right > 0:
                    generate(left, right - 1, s + ')')
        generate(n, n, '')
        return res
