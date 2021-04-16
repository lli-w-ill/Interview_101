#include <vector>

using std::vector;

class Solution_3 {
public:
    void gameOfLife(vector<vector<int>>& board) {
        //          左上  左  左下 上   下  右上 右  右下
        int dx[] = {-1,  0,  1,   -1,  1, -1,  0, 1};
        int dy[] = {-1,  -1, -1,  0,   0, 1,   1, 1};

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                int sum = 0;

                // 计算八个方向的活细胞数
                for (int k = 0; k < 8; k++) {
                    int newx = i + dx[k];
                    int newy = j + dy[k];
                    // 检查不越界
                    if (newx >= 0 && newx < board.size() && newy >= 0 && newy < board[i].size()) {
                        sum += (board[newx][newy] & 1);     // 只取32bit中最低的一位
                    }
                }

                // 分类讨论
                if (board[i][j] == 1) {
                    if (sum == 2 || sum == 3) {
                        board[i][j] |= 2;   // 2 = 10 (32位 bit)
                    }
                } else {
                    if (sum == 3) {
                        board[i][j] |= 2;   // 2 = 10 (32位 bit)
                    }
                }
            }
        }

        // 最后，所有位置上的值都右移一位 bit
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                board[i][j] >>= 1;  // 右数第二位 bit 才是更新后的结果
            }
        }
    }
};

// 参考题解：https://leetcode-cn.com/problems/game-of-life/solution/c-wei-yun-suan-yuan-di-cao-zuo-ji-bai-shuang-bai-b/
