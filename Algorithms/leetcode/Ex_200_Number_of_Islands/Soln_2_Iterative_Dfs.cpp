#include <vector>
#include <utility>
#include <stack>

using std::vector;
using std::pair;
using std::stack;

class Solution_2 {
public:
    int numIslands(vector<vector<char> >& grid) {
        int rows = grid.size();
        int res = 0;    // 记录岛屿数
        if (rows == 0) {
            return res;
        }
        int cols = grid[0].size();
        // 保存方向
        vector<pair<int, int> > direction;
        // 添加四个方向：上、左、下、右
        direction.push_back(pair<int, int> (-1, 0));
        direction.push_back(pair<int, int> (0, -1));
        direction.push_back(pair<int, int> (1, 0));
        direction.push_back(pair<int, int> (0, 1));
        // 利用栈，记录要访问的下标
        stack<pair<int, int> > st;
        // 开始 dfs
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1') {
                    res += 1;
                    // 将当前下标加入栈，然后以当前下标进行dfs搜索
                    st.push(pair<int, int> (r, c));
                    while (!st.empty()) {
                        pair<int, int> top = st.top();
                        st.pop();
                        int rr = top.first;
                        int cc = top.second;
                        // 首先将当前位置置为「海洋」，防止“回头”
                        grid[rr][cc] = '0';
                        // 然后检查四个方向加，如果某一方向是陆地，则将对应行列入栈
                        for (vector<pair<int, int> >::const_iterator it = direction.begin(); it != direction.end(); it++) {
                            int new_rr = rr + it->first;
                            int new_cc = cc + it->second;
                            if (new_rr < 0 || new_rr >= rows || new_cc < 0 || new_cc >= cols) {
                                // 首先检查是否越界
                                continue;
                            } else if (grid[new_rr][new_cc] == '0') {
                                // 其次检查新位置是否是「海洋」
                                continue;
                            } else {
                                st.push(pair<int, int> (new_rr, new_cc));
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};
