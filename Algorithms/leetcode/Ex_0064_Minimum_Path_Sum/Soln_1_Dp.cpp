#include <vector>
#include <algorithm>

using std::vector;
using std::min;

class Solution_1 {
public:
    int minPathSum(vector<vector<int> >& grid) {
        int rows = grid.size();
        if (rows == 0) {
            return 0;
        }
        int cols = grid[0].size();
        // 首先初始化最后一行：因为从右下角往左只有一条路，所以最后一行前一个cell的最短路径=其后一个cell的最短路径+自身的数字
        for (int c = cols - 2; c >= 0; c--) {
            grid[rows-1][c] += grid[rows-1][c+1];
        }
        // 其次初始化最后一列：因为从右下角往上只有一条路，所以最后一列上一个cell的最短路径=其下一个cell的最短路径+自身的数字
        for (int r = rows - 2; r >= 0; r--) {
            grid[r][cols-1] += grid[r+1][cols-1];
        }
        // 全部初始化后，接下来还是从最右下角的cell的左上角的cell开始（以例子图为例，就是从5开始），逐行向上更新grid值，且每行从倒数第二列开始向左一直到第一列
        for (int r = rows - 2; r >= 0; r--) {
            for (int c = cols - 2; c >= 0; c--) {
                // 从其下面的cell和其右边的cell到右下角的最短路径中，选出更短的，然后加上自身的数字，就是从当前的(r, c)到右下角的最短路径
                grid[r][c] += min(grid[r+1][c], grid[r][c+1]);
            }
        }
        return grid[0][0];
    }
};

// 注：这道题和Ex62题有异曲同工之处
