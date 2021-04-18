#include <vector>

using std::vector;

class Tle_2 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if (rows == 0) {
            return false;
        }
        int cols = matrix[0].size();
        return searchBasedOnBottomRight(matrix, target, rows - 1, cols - 1); 
    }

private:
    bool searchBasedOnBottomRight(vector<vector<int>> &matrix, int target, int r, int c) {
        // cout << r << " " << c << endl;
        if (r < 0 || c < 0) {
            return false;
        }
        if (target > matrix[r][c]) {
            return false;
        }
        if (matrix[r][c] == target) {
            return true;
        }
        // 每次削去一列／一行
        return searchBasedOnBottomRight(matrix, target, r, c - 1) || searchBasedOnBottomRight(matrix, target, r - 1, c);
    }
};

// 时间复杂度：O(Rows + Cols) ———— 最坏情况从右上角走到左下角
// 空间复杂度：O(1)
// 这个解法利用了：右下角的元素值一定是：「以从(0,0)到该元素所围成的矩阵」的最大值

