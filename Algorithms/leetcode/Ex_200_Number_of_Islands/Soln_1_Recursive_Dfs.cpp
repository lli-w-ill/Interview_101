#include <vector>
#include <utility>

using std::vector;
using std::pair;

class Solution_1 {
public:
    int numIslands(vector<vector<char> >& grid) {
        int rows = grid.size();
        if (rows == 0) {
            return res;
        }
        int cols = grid[0].size();
        // 添加四个方向：上、左、下、右
        direction.push_back(pair<int, int> (-1, 0));
        direction.push_back(pair<int, int> (0, -1));
        direction.push_back(pair<int, int> (1, 0));
        direction.push_back(pair<int, int> (0, 1));
        // 开始 dfs
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1') {
                    res += 1;
                    dfs(grid, rows, cols, r, c);
                }
            }
        }
        return res;
    }

private:
    // 保存方向
    vector<pair<int, int> > direction;
    // 记录岛屿数
    int res = 0;

    // 返回
    void dfs(vector<vector<char> > &grid, int rows, int cols, int r, int c) {
        // 检查越界
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            return;
        }
        // base case
        if (grid[r][c] != '1') {
            return;
        } else {
            // 将当前的位置设为「海水」，防止“回头”
            grid[r][c] = '0';
            // 访问当前位置的四个方向
            for (vector<pair<int, int> >::const_iterator it = direction.begin(); it != direction.end(); it++) {
                dfs(grid, rows, cols, r + it->first, c + it->second);
            }
        }
    }
};
