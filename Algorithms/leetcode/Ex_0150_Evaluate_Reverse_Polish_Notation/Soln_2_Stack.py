class Solution_2:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for token in tokens:
            try:
                # 先尝试按照数字处理
                stack.append(int(token))
            except:
                # 如果转换int中抛出异常，则说明是运算符
                num2 = stack.pop()
                num1 = stack.pop()
                stack.append(self.evaluate(num1, num2, token))
        return stack[0]
    
    def evaluate(self, num1: int, num2: int, operator: str) -> int:
        if operator == "+":
            return num1 + num2
        elif operator == "-":
            return num1 - num2
        elif operator == "*":
            return num1 * num2
        elif operator == "/":
            # 注意python中 // 是向下取整而不是向零取整，所以//遇到负数会出问题
            # 解决方法见参考题解
            return int(num1 / float(num2))

# 参考题解（非常推荐，很多python特有的坑）：https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/solution/xiang-jie-ni-bo-lan-biao-da-shi-fu-ben-t-sfl6/
