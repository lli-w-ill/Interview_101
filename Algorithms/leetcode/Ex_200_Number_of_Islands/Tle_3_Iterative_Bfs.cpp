#include <vector>
#include <utility>
#include <queue>

using std::vector;
using std::pair;
using std::queue;

class Tle_3 {
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
        queue<pair<int, int> > queue;
        // 开始 dfs
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1') {
                    res += 1;
                    // 将当前下标加入栈，然后以当前下标进行dfs搜索
                    queue.push(pair<int, int> (r, c));
                    while (!queue.empty()) {
                        pair<int, int> top = queue.front();
                        queue.pop();
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
                                queue.push(pair<int, int> (new_rr, new_cc));
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};

// 代码上来看与 DFS 相比，BFS 除了用的数据结构从 stack 改为 queue，没有其他区别（可以对比 Soln_2 的代码）
// 访问路线上来看与 DFS 相比，DFS 是从每一个第一次发现的陆地位置「一条道走到非陆地位置才回头」，而 BFS 则是从每一个第一次发现的陆地位置「先逐个访问其四个方向上的位置，再逐渐向外扩散」
