#include <vector>
#include <queue>
#include <utility>

using std::vector;
using std::queue;
using std::pair;

class Solution_1 {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = (m == 0) ? 0 : mat[0].size();

        if (m == 0 || n == 0) {
            return mat;
        }

        vector<int> directions {-1, 0, 1, 0, -1};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    // 从 (i, j) 点开始做 BFS，找到最近的 0
                    queue<pair<int, int>> level;
                    level.push({i, j});
                    int minDistance = 1;    // 记录最小距离
                    int x;
                    int y;
                    bool foundZero = false;
                    
                    // 开始 BFS
                    while (!level.empty()) {
                        int size = level.size();

                        while (size > 0) {
                            // 遍历当前层的所有节点
                            auto [r, c] = level.front();
                            level.pop();

                            // 尝试 上、下、左、右 方向
                            for (int k = 0; k < directions.size() - 1; k++) {
                                x = r + directions[k];
                                y = c + directions[k + 1];

                                // 检查越界
                                if (x < 0 || x >= m || y < 0 || y >= n) {
                                    continue;
                                }

                                if (mat[x][y] == 0) {
                                    foundZero = true;
                                    break;
                                } else {
                                    level.push({x, y});
                                }
                            }
                            // 检查是否已经找到最近的 0，如果已经找到了就不再继续向 4 个方向上找 0 了
                            if (foundZero == true) {
                                break;
                            }
                            size --;
                        }
                        // 检查是否已经找到最近的 0，如果已经找到了，就不用在同层的其他临界位置上寻找 0 了
                        if (foundZero == true) {
                            break;
                        }
                        // 每 run 完一层 BFS，和最近的 0 的最短距离累加一
                        minDistance ++;
                    }

                    mat[i][j] = minDistance;

                }
            }
        }

        return mat;
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
// 思路：在每个 mat[i][j] = 1 的位置上跑一遍 BFS，寻找最近的 0 节点
// 
// 设 m = mat.size(), n = mat[0].size()
// time complexity: O(m^2 * n^2)
// space complexity: O(m * n)
