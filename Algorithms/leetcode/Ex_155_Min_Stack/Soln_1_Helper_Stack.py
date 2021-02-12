class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        # stack存储(当前值，当前最小值)的tuples
        self.stack = []

    def push(self, x: int) -> None:
        # self.stack[-1][1]代表当前最小的值
        if not self.stack or x < self.stack[-1][1]:
            self.stack.append((x, x))
        else:
            self.stack.append((x, self.stack[-1][1]))

    def pop(self) -> None:
        _, _ = self.stack.pop()

    def top(self) -> int:
        return self.stack[-1][0]

    def getMin(self) -> int:
        return self.stack[-1][1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
