#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;
using std::max;
using std::cout;
using std::endl;

class Err_1 {
public:
    int largestIsland(vector<vector<int> >& grid) {
        int res = 0;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[r].size(); c++) {
                int area = 0;
                if (grid[r][c] == 1) {
                    res = max(res, dfs(grid, r, c, area));
                } else if (grid[r][c] == 0) {
                    // 先将当前位置变为陆地
                    grid[r][c] = 1;
                    // 计算最大岛屿面积
                    res = max(res, dfs(grid, r, c, area));
                    // 恢复状态（回溯）
                    grid[r][c] = 0;
                }
                cout << r << " " << c << " " << area << endl;
                for (int i = 0; i < grid.size(); i++)
                {
                    for (int j = 0; j < grid[i].size(); j++)
                    {
                        cout << grid[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << endl;
            }
        }
        return res;
    }

private:
    int dfs(vector<vector<int> > &grid, int r, int c, int &area) {
        if (!inArea(grid, r, c)) {
            // 越界
            return area;
        }
        if (grid[r][c] == 2 || grid[r][c] == 0) {
            // 已经访问过 或 当前位置为海洋
            return area;
        }
        // 累加面积
        area += 1;
        // 将当前位置置为「已经访问」
        grid[r][c] = 2;
        cout << r << " " << c << " " << grid[r][c] << " " << area << endl;
        // 访问四个方向：上、左、下、右
        dfs(grid, r - 1, c, area);
        dfs(grid, r, c - 1, area);
        dfs(grid, r + 1, c, area);
        dfs(grid, r, c + 1, area);
        // 恢复状态回溯（防止污染grid，在主函数下次调用dfs将污染后的grid传给dfs）
        grid[r][c] = 1;
        return area;
    }

    bool inArea(vector<vector<int> > &grid, int r, int c) {
        return r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size();
    }
};


int main() {
    Err_1 s;
    vector<vector<int> > grid;
    vector<int> temp;
    temp.push_back(1);
    temp.push_back(1);
    grid.push_back(temp);
    temp.clear();
    temp.push_back(1);
    temp.push_back(0);
    grid.push_back(temp);
    s.largestIsland(grid);
    return 0;
}

// 这里的思路是：让每一个海洋格子经历一次「填海造路」的经历，然后遍历填海后的最大陆地面积，因为填海后的面积一定比未填海时要大，因为面积一定会 +1（除非原地图就是全1）
// 这个code错误很不好发现，因为当回溯前恢复状态之后，area没有递减，所以当起始位置 r = 1, c = 1 会出现问题，但是 area 又不能递减，因为如果 area 跟随每次回溯递减，最后返回一定是 0。建议 debug 一遍，花了大半天照这个问题。。
// 这里的未通过的测试用例是 
//      1 1
//      1 0
// 
// 注：根据题解 https://leetcode-cn.com/problems/making-a-large-island/solution/zui-da-ren-gong-dao-by-leetcode/，这个想法会超时，因为时间复杂度是 O(n^4), OMG. 代码实现详见 Tle_3。
