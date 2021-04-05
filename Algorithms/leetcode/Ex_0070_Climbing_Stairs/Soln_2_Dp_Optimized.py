class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1: 
            return 1
        if n == 2: 
            return 2
        last = 1            # 初始值为倒数第一阶方案数，只有一种方案（登1个台阶），之后表示位于「当前台阶+2」时的方案数
        secondLast = 2      # 初始值为倒数第二阶方案数，有两种方案（登1个或2个台阶），之后表示位于「当前台阶+1」时的方案数
        cur = 0             # 「位于当前台阶」的方案数
        # e.g. n = 5
        # 0  1  2  3  4  5
        #       ^  ^  ^  ^
        #       |  |  |  0
        #       |  |  last=1
        #       |  secondLast=2
        #       cur=1+2=3
        #  
        # 0  1  2  3  4  5
        #    ^  ^  ^
        #    |  |  last=2
        #    |  secondLast=3
        #    cur=2+3=5
        #
        # 0  1  2  3  4  5
        # ^  ^  ^
        # |  |  last=3
        # |  secondLast=5
        # cur=3+5=8   
        for i in range(n-2):   # 循环从倒数第三阶开始算，一共需要登n个台阶，所以一共循环n-3次
            cur = last + secondLast
            last = secondLast
            secondLast = cur
        return cur

# 优化点：空间复杂度O(n) -> O(1)
