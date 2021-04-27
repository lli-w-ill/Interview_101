#include <vector>
#include <stack>

using std::vector;
using std::max;
using std::stack;
using std::pair;

class Solution_3 {
public:
    int maxAreaOfIsland(vector<vector<int> >& grid) {
        vector<int> directions {-1, 0, 1, 0, -1};

        int m = grid.size();
        int n = (m == 0) ? 0 : grid[0].size();
        int local_area;     // 记录每块岛屿的面积
        int max_area = 0;
        int x;
        int y;

        // 主函数：遍历所有位置
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    // 可以从当前位置开始 DFS，这里采用显式栈实现 DFS
                    // （如果是递归实现，从这里开始掉用辅函数）
                    // 初始化
                    local_area = 1;
                    stack<pair<int, int>> island;   // 记录当前岛屿的访问过的陆地位置
                    island.push({i, j});
                    // 将当前位置置为海洋，避免无限循环
                    grid[i][j] = 0;
                    
                    // 开始迭代 DFS
                    while (!island.empty()) {
                        auto [r, c] = island.top();
                        island.pop();
                        for (int k = 0; k < directions.size() - 1; k++) {
                            // 更新下一个位置
                            x = r + directions[k];
                            y = c + directions[k+1];

                            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                                local_area ++;
                                island.push({x, y});
                                grid[x][y] = 0;
                            }
                        }
                    }

                    // 每次访问完一块岛屿后，更新最大面积
                    max_area = max(max_area, local_area);
                }
            }
        }

        return max_area;
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
