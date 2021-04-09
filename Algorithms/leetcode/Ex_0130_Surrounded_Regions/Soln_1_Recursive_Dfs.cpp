#include <set>
#include <list>
#include <vector>
#include <utility>

using std::set;
using std::list;
using std::vector;
using std::pair;
using std::make_pair;

class Solution_1 {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        if (m == 1 || n == 1) {
            return;
        }

        // 记录已被访问过的坐标
        set<pair<int, int>> visited;

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (board[i][j] == 'O' && visited.find(std::make_pair(i, j)) == visited.end()) {
                    // 将相邻的 O 全部加入到一个 list
                    list<pair<int, int>> li;
                    bool hasZeroCoordinate = false;
                    dfs(board, m, n, i, j, visited, li, hasZeroCoordinate);

                    // 检查 list 中是否存在横坐标或纵坐标为 0 的
                    if (hasZeroCoordinate == false) {
                        // 如果没有在四个边上的 O，那么将 li 中所有的坐标都置为 X
                        for (pair<int, int> &pair : li) {
                            board[pair.first][pair.second] = 'X';
                        }
                    }
                }
            }
        }
    }

private:
    void dfs(const vector<vector<char>> &board, int m, int n, int i, int j, set<pair<int, int>> &visited, list<pair<int, int>> &li, bool &hasZeroCoordinate) {
        // base cases
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return;
        }
        if (board[i][j] == 'X') {
            return;
        }
        if (visited.find(make_pair(i, j)) != visited.end()) {
            // 坐标 (i, j) 已经被访问过
            return;
        }

        li.insert(li.end(), make_pair(i, j));
        visited.insert(make_pair(i, j));

        if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
            hasZeroCoordinate = true;
        }

        // 上
        dfs(board, m, n, i-1, j, visited, li, hasZeroCoordinate);
        // 右
        dfs(board, m, n, i, j+1, visited, li, hasZeroCoordinate);
        // 下
        dfs(board, m, n, i+1, j, visited, li, hasZeroCoordinate);
        // 左
        dfs(board, m, n, i, j-1, visited, li, hasZeroCoordinate);
        
    }
};
