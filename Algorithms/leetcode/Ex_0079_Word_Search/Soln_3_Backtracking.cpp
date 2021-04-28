#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution_3 {
public:
    bool exist(vector<vector<char> >& board, string word) {
        int m = board.size();
        int n = (m == 0) ? 0 : board[0].size();
        if (m * n < word.size()) {
            return false;
        }

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        bool find = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                backtracking(i, j, board, word, find, visited, 0);
            }
        }

        return find;
    }

private:
    vector<int> directions {-1, 0, 1, 0, -1};

    // 这里回溯采用：不管三七二十一，先向四个方向递归，再在下一层的开始检查越界的策略
    void backtracking(int i, int j, const vector<vector<char>> &board, const string &word, bool &find, vector<vector<bool>> &visited, int word_pos) {
        // 检查越界
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) {
            return;
        }
        // 检查当前位是否已经访问
        if (visited[i][j] == true) {
            return;
        }
        // 检查当前 word 是否已经找到
        if (find == true) {
            return;
        }
        // 检查当前位是否与 word 中要找到当前位相同
        if (word[word_pos] != board[i][j]) {
            return;
        } else if (word[word_pos] == board[i][j] && word_pos == word.size() - 1) {
            find = true;
            return;
        }

        visited[i][j] = true;   // 修改当前节点状态

        // 递归子节点
        int x;
        int y;
        for (int k = 0; k < directions.size() - 1; k++) {
            x = i + directions[k];
            y = j + directions[k + 1];
            backtracking(x, y, board, word, find, visited, word_pos + 1);
        }

        visited[i][j] = false;  // 恢复当前节点状态

    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
