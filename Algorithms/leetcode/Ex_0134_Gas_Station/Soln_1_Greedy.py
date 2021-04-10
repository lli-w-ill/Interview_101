from collections import defaultdict


class Solution_1:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        # 保存 gas[i]/cost[i] 的比例，每次从尽可能 ratio 大的 i 出发，这样刚开始可以有尽可能多的油
        ratio = defaultdict(int)
        for i in range(len(gas)):
            if cost[i] == 0:
                # 避免除零
                ratio[i] = float('inf')
            else:
                ratio[i] = gas[i] / cost[i]
        # 按 ratio 从大到小排序
        ratio = sorted(ratio, reverse=True, key=lambda x: ratio[x])

        for startPos in ratio:
            if self.canComplete(gas, cost, startPos, gas[startPos], [startPos]):
                return startPos
        return -1
    
    def canComplete(self, gas: List[int], cost: List[int], curPos: int, leftGas: int, path: List[int]) -> bool:
        # base cases
        if len(path) == len(gas) + 1:
            return True
        if leftGas < cost[curPos]:
            # 如果当前剩的油不支持到下一个站点，那么放弃
            return False

        nextPos = (curPos + 1) % len(gas)

        if len(path) < len(gas):
            return self.canComplete(gas, cost, nextPos, leftGas - cost[curPos] + gas[nextPos], path + [nextPos])
        elif len(path) == len(gas):
            # 最后一次不能加上起始点的油
            return self.canComplete(gas, cost, nextPos, leftGas - cost[curPos], path + [nextPos])

