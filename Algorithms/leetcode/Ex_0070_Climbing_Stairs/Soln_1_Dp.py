class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1: 
            return 1
        if n == 2: 
            return 2
        steps = [-1] * (n+1)
        steps[-1] = 0   # 终点
        steps[-2] = 1   # 倒数第一阶只有一种方案（登1个台阶）
        steps[-3] = 2   # 倒数第二阶有两种方案（登1个或2个台阶）
        for i in range(n-3, -1, -1):
            steps[i] = steps[i+1] + steps[i+2]
        return steps[0]
