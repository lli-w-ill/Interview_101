#include <vector>

using std::vector;

class Solution_1 {
public:
    void rotate(vector<vector<int> >& matrix) {
        int rows = matrix.size();
        if (rows == 0) {
            return;
        }
        int cols = matrix[0].size();
        // 首先对matrix进行转置，m[i][j] = m[j][i]
        // 注意，循环变量只循环一半即可（这里我选择的是matrix的左下半部分），否则会转置两遍，结果等于没转制
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < r; c++) {
                int temp = matrix[r][c];
                matrix[r][c] = matrix[c][r];
                matrix[c][r] = temp;
            }
        }
        // 然后对转置后的matrix进行左右镜像交换
        // 同样注意，列坐标只循环到一半就行，否则也会交换两遍等于没交换
        for (int c = 0; c < cols / 2; c++) {
            for (int r = 0; r < rows; r++) {
                int temp = matrix[r][c];
                matrix[r][c] = matrix[r][cols - c - 1];
                matrix[r][cols - c - 1] = temp;
            }
        }
    }
};
