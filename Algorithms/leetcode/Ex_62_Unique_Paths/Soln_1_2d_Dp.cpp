#include <vector>

using std::vector;

class Solution_1 {
public:
    int uniquePaths(int m, int n) {
        // 特判
        if (m == 1 && n == 1) {
            return 1;
        }
        vector<vector<int> > matrix (m, vector<int> (n, 0));
        matrix[m-1][n-1] = 0;   // 终点(m-1, n-1)
        // 由于每次只能向下或者向右，所以初始化最后一行和最后一列为1
        for (int c = 0; c < n - 1; c++) {
            matrix[m-1][c] = 1;
        }
        for (int r = 0; r < m - 1; r++) {
            matrix[r][n-1] = 1;
        }
        // 从右下角开始，从最后一行逐行向上填充matrix，每行填充顺序为从右向左
        //  <=============== 1
        //  <=============== 1
        // 1 1 1 1 1 1 1 1 1 0
        for (int r = m - 2; r >= 0; r--) {
            for (int c = n - 2; c >= 0; c--) {
                matrix[r][c] = matrix[r+1][c] + matrix[r][c+1];
            }
        }
        return matrix[0][0];
    }
};
