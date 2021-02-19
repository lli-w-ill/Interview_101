#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) {
        // 特判
        if (word.size() == 0) {
            return true;
        }
        int rows = board.size();
        int cols = board[0].size();
        if (rows == 0 && cols == 0) {
            return false;
        }
        if (rows * cols < word.size()) {
            return false;
        }
        // 开始dfs搜索，寻找起点
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] == word[0] && dfs(board, rows, cols, r, c, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private: 
    bool dfs(vector<vector<char> > &board, int rows, int cols, int r, int c, string word, int wordIdx) {
        if (wordIdx == word.size()) {
            return true;
        }
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            // 越界
            return false;
        }
        if (board[r][c] == word[wordIdx]) {
            // 分别向上、向左、向下、向右
            // 只要有一个返回true，就代表找到了一条组成word单词的路径
            // 所有参数只需要改变r, c和递增wordIdx
            char temp = board[r][c];    // 保存下当前位置的字符
            board[r][c] = '#';  // 这里需要将当前位置置为特殊标识，防止下一步“回头”重复走已经走过的路（很重要）
            // 向上
            if (dfs(board, rows, cols, r - 1, c, word, wordIdx + 1)) {
                return true;
            }
            // 向左
            if (dfs(board, rows, cols, r, c - 1, word, wordIdx + 1)) {
                return true;
            }
            // 向下
            if (dfs(board, rows, cols, r + 1, c, word, wordIdx + 1)) {
                return true;
            }
            // 向右
            if (dfs(board, rows, cols, r, c + 1, word, wordIdx + 1)) {
                return true;
            }
            // 恢复状态（回溯）
            board[r][c] = temp;
            return false;
        } else {
            return false;
        }
    }
};
