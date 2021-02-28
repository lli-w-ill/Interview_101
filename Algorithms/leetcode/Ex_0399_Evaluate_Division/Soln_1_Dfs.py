from collections import defaultdict

class Solution_1:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        # map[a][b] = a / b
        # map[b][a] = b / a
        map = defaultdict(dict)
        # 建图
        for i in range(len(equations)):
            a, b = equations[i]
            val = values[i]     # a / b 的结果
            map[a][b] = val
            map[b][a] = 1 / val
        # 求解
        res = []
        for a, b in queries:
            res.append(self.dfs(a, b, 1, map, set()))
        return res
    
    def dfs(self, start: str, target: str, result: float, mmap: Dict[str, Dict[str, int]], visited: Set[str]) -> float:
        # base case
        if start not in mmap:
            return -1.0
        if start in visited:
            return -1.0
        if start == target:
            return result
        for nextStart in mmap[start].keys():
            res = self.dfs(nextStart, target, result * mmap[start][nextStart], mmap, visited | {start})
            if res != -1.0:
                return res
        return -1.0
    
# 参考以前提交的代码
