#include <vector>

using std::vector;

class Solution_1 {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = (m == 0) ? 0 : heights[0].size();

        if (m == 0 || n == 0) {
            return vector<vector<int>> {};
        }

        // 从矩阵的四条边向中心进行「反重力」搜索
        // 记录每个位置是否可以到达 太平洋 ／ 大西洋
        vector<vector<bool>> can_reach_pacific(m, vector<bool> (n, false));
        vector<vector<bool>> can_reach_atlantic(m, vector<bool> (n, false));

        // 从最左／最右两条边开始向中心搜索
        for (int i = 0; i < m; i++) {
            // 从最左的纵向的「太平洋边」开始
            dfs(heights, can_reach_pacific, i, 0);
            // 从最右的纵向的「大西洋边」开始
            dfs(heights, can_reach_atlantic, i, n - 1);
        }

        // 从最上／最下两条边开始向中心搜索
        for (int i = 0; i < n; i++) {
            // 从最上的横向的「太平洋边」开始
            dfs(heights, can_reach_pacific, 0, i);
            // 从最下的横向的「大西洋边」开始
            dfs(heights, can_reach_atlantic, m - 1, i);
        }

        // 遍历一遍 matrix，收集既能到达太平洋，也能到达大西洋的点
        vector<vector<int>> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (can_reach_pacific[i][j] && can_reach_atlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        
        return res;
    }

private:
    vector<int> directions {-1, 0, 1, 0, -1};

    void dfs(const vector<vector<int>> &heights, vector<vector<bool>> &can_reach_pacific_or_atlantic, int r, int c) {
        if (can_reach_pacific_or_atlantic[r][c] == true) {
            return;
        }

        can_reach_pacific_or_atlantic[r][c] = true;
        int x;
        int y;
        
        for (int i = 0; i < directions.size() - 1; i++) {
            // 计算新位置
            x = r + directions[i];
            y = c + directions[i + 1];

            // 判断新位置是否合法
            if (x >= 0 && x < heights.size() && y >= 0 && y < heights[0].size()) {
                // 判断是否是「反重力方向」
                if (heights[r][c] <= heights[x][y]) {
                    dfs(heights, can_reach_pacific_or_atlantic, x, y);
                }
            }
        }
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
