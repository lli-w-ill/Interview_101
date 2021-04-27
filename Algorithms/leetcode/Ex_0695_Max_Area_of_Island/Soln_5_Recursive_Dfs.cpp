#include <vector>

using std::vector;
using std::max;

class Solution_5 {
public:
    // 主函数
    int maxAreaOfIsland(vector<vector<int> >& grid) {
        int max_area = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    max_area = max(max_area, dfs(grid, i, j));
                }
            }
        }

        return max_area;
    }

private:
    vector<int> directions {-1, 0, 1, 0, -1};

    // 辅函数：（第二种策略）不管新位置是否越界，先递归，让下一层递归的开始去判断是否越界问题
    int dfs(vector<vector<int>> &grid, int r, int c) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) {
            // 越界
            return 0;
        }
        if (grid[r][c] == 0) {
            return 0;
        }
        
        grid[r][c] = 0;
        int x;
        int y;
        int local_area = 1;

        for (int i = 0; i < directions.size() - 1; i++) {
            // 计算下一个搜索位置
            x = r + directions[i];
            y = c + directions[i+1];

            local_area += dfs(grid, x, y);
        }

        return local_area;
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394

