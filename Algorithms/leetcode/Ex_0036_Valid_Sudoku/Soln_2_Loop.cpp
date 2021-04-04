#include <vector>

using std::vector;

class Solution_2 {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][10] = {0};   // 保存每一行每个数是否出现过
        int col[9][10] = {0};   // 保存每一列每个数是否出现过
        int box[9][10] = {0};   // 保存每一个3x3box每个数是否出现过

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') 
                    continue;
                int num = board[i][j] - '0';
                if (row[i][num])
                    // 如果第 i 行已经出现过数字 num
                    return false;
                if (col[j][num])
                    // 如果第 j 列已经出现过数字 num
                    return false;
                if (box[(i/3) * 3 + j/3][num])
                    // 如果第 (i/3)*3 + j/3 个 3x3 box 已经出现过数字num
                    return false;
                
                row[i][num] = 1;
                col[j][num] = 1;
                box[(i/3) * 3 + j/3][num] = 1;
            }
        }

        return true;
    }
};

// 参考题解：https://leetcode-cn.com/problems/valid-sudoku/solution/36-jiu-an-zhao-cong-zuo-wang-you-cong-shang-wang-x/


