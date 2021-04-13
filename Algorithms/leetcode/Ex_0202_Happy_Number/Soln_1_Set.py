class Solution_1:
    def isHappy(self, n: int) -> bool:
        oldNs = set()
        while n != 1 and n not in oldNs:
            oldNs.add(n)
            newN = 0
            while n > 0:
                newN += (n % 10) ** 2
                n = n // 10
            n = newN
            # print(n)
        
        return n == 1

# 想法：其实 set 是可以省去的，因为如果是一个循环，那么记住一个数就好了
# 这个想法其实不成立，因为出现循环不一定会回到第一个 firstN，也有可能在中间某个地方无限循环
