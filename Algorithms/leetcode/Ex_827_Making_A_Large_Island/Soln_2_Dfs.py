import collections

class Solution_2:
    def largestIsland(self, grid: List[List[int]]) -> int:
        # key: island tag
        # value: island area
        island2Area = collections.defaultdict(int)
        island2Area[0] = 0
        # 每个岛屿的特殊字符
        tag = 100
        rows = len(grid)
        cols = len(grid[0])
        # 开始第一遍 dfs：计算每个岛屿的面积，并标记每个岛屿为特殊符号 tag
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 1:
                    self.dfs(grid, r, c, tag, island2Area)
                    tag += 1    # 更新tag，避免岛屿之间的特殊符号冲突

        # print(grid)
        # print(island2Area)

        # 开始第二遍 dfs，遍历 grid 中所有海洋格子，观察它们四个方向
        res = 0
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 0:
                    # 当前为海洋格子
                    # 观察上、左、下、右四个方向，如果相邻是陆地格子，就在 map 中根据它们的特殊符号找到他们的面积，并累加面积
                    area = 1
                    visitedIslandTag = set()    # 注意一定不要加重，所以需要一个set来记录已经加过area的陆地的特殊符号
                    if self.inArea(grid, r - 1, c) and grid[r-1][c] in island2Area and grid[r-1][c] not in visitedIslandTag:
                        # 上
                        area += island2Area[grid[r-1][c]]
                        visitedIslandTag.add(grid[r-1][c])
                    if self.inArea(grid, r, c - 1) and grid[r][c-1] in island2Area and grid[r][c-1] not in visitedIslandTag:
                        # 左
                        area += island2Area[grid[r][c-1]]
                        visitedIslandTag.add(grid[r][c-1])
                    if self.inArea(grid, r + 1, c) and grid[r+1][c] in island2Area and grid[r+1][c] not in visitedIslandTag:
                        # 下
                        area += island2Area[grid[r+1][c]]
                        visitedIslandTag.add(grid[r+1][c])
                    if self.inArea(grid, r, c + 1) and grid[r][c+1] in island2Area and grid[r][c+1] not in visitedIslandTag:
                        # 右
                        area += island2Area[grid[r][c+1]]
                        visitedIslandTag.add(grid[r][c+1])
                    # 更新最大岛屿面积
                    res = max(res, area)
        # 检查是否res依然为0，如果res=0，就说明 grid 中没有海洋格子，原grid是全1，所以返回rows*cols
        if res == 0:
            return rows * cols
        else:
            return res
        
    def dfs(self, grid: List[List[int]], r: int, c: int, tag: int, island2Area: Dict[int, int]) -> None:
        if not self.inArea(grid, r, c):
            return
        if grid[r][c] != 1:
            return
        # 将当前位置设为岛屿的特殊符号，并更新 map
        grid[r][c] = tag
        island2Area[tag] = island2Area.get(tag, 0) + 1
        # 分别访问其上、左、下、右四个方向
        self.dfs(grid, r - 1, c, tag, island2Area)
        self.dfs(grid, r, c - 1, tag, island2Area)
        self.dfs(grid, r + 1, c, tag, island2Area)
        self.dfs(grid, r, c + 1, tag, island2Area)

    def inArea(self, grid: List[List[int]], r: int, c: int) -> bool:
        return r >= 0 and r < len(grid) and c >= 0 and c < len(grid[0])


# 参考题解：https://leetcode-cn.com/problems/number-of-islands/solution/dao-yu-lei-wen-ti-de-tong-yong-jie-fa-dfs-bian-li-/
# 思路：
# 第一遍dfs：先计算出每个岛屿的面积，并在将每个岛屿用特殊的数字标记，同时用一个 map 来保存「从每个岛屿特殊的标记」 到 「该岛屿的面积」 的一个映射
# 第二遍dfs：遍历所有海洋格子（即0），观察每个海洋格子的相邻陆地格子
