#include <vector>

using std::vector;

class Solution_1 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if (rows == 0) {
            return false;
        }
        int cols = matrix[0].size();
        // 从右上角开始
        // 如果 target > matrix[r][c] 那么往下走
        // 如果 target < matrix[r][c] 那么往左走
        int r = 0;
        int c = cols - 1;
        while (r < rows && c >= 0) {
            if (target == matrix[r][c]) {
                return true;
            } else if (target > matrix[r][c]) {
                r += 1;
            } else if (target < matrix[r][c]) {
                c -= 1;
            }
        }
        return false;
    }
};

// 时间复杂度：O(Rows + Cols) ———— 最坏情况从右上角走到左下角
// 空间复杂度：O(1)

