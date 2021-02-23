#include <vector>
#include <algorithm>

using std::vector;
using std::max;

class Solution_1 {
public:
    int maxAreaOfIsland(vector<vector<int> >& grid) {
        int res = 0;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[r].size(); c++) {
                if (grid[r][c] == 1) {
                    int area = 0;
                    res = max(res, dfs(grid, r, c, area));
                }
            }
        }
        return res;
    }

private:
    // 返回当前位置所在岛屿的面积
    int dfs(vector<vector<int> > &grid, int r, int c, int &area) {
        if (!inArea(grid, r, c)) {
            return area;
        }
        if (grid[r][c] != 1) {
            return area;
        }
        area += 1;
        // 将当前位置置为「已经访问过」，防止「兜圈子」
        grid[r][c] = 2;
        // 分别访问其上、下、左、右四个方向
        dfs(grid, r - 1, c, area);
        dfs(grid, r, c - 1, area);
        dfs(grid, r + 1, c, area);
        dfs(grid, r, c + 1, area);
        return area;
    }

    bool inArea(vector<vector<int> > &grid, int r, int c) {
        return r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size();
    }
};

// 这道题配合题解 https://leetcode-cn.com/problems/number-of-islands/solution/dao-yu-lei-wen-ti-de-tong-yong-jie-fa-dfs-bian-li-/ 中提到的其他网格类题非常棒

