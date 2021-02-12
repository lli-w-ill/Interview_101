class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        # 数据栈
        self.data = []
        # 同步辅助栈
        self.helper = []

    def push(self, x: int) -> None:
        self.data.append(x)
        if not self.helper or x <= self.helper[-1]:
            self.helper.append(x)

    def pop(self) -> None:
        if self.data:
            val = self.data.pop()
            if self.helper and val == self.helper[-1]:
                self.helper.pop()

    def top(self) -> int:
        if self.data:
            return self.data[-1]

    def getMin(self) -> int:
        if self.helper:
            return self.helper[-1]


# 参考：https://leetcode-cn.com/problems/min-stack/solution/shi-yong-fu-zhu-zhan-tong-bu-he-bu-tong-bu-python-/

# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
