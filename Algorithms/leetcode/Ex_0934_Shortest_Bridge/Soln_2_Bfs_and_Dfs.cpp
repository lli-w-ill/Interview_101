#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;

class Solution_2 {
public:
    int shortestBridge(vector<vector<int>>& A) {
        int m = A.size();
        int n = (m == 0) ? 0 : A[0].size();
        queue<pair<int, int>> firstIslandQueue;
        bool foundFirstIsland = false;

        // 先用 DFS 找到第一块岛屿，并将第一块岛屿陆地位置置为 2，且将边缘陆地连接的海洋位置加入 queue 中
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (foundFirstIsland == true) {
                    break;
                }

                if (A[i][j] == 1) {
                    // 找到了第一块岛屿的第一片陆地
                    foundFirstIsland = true;
                    // 开始 DFS 置位 2 并加入 queue
                    dfs(A, i, j, m, n, firstIslandQueue);
                    break;
                }
            }
            if (foundFirstIsland == true) {
                break;
            }
        }

        // 再以第一个岛屿所有边界海洋位置为起点，寻找第二个岛屿
        int x;
        int y;
        int min_distance = 0;
        while (!firstIslandQueue.empty()) {
            int level_size = firstIslandQueue.size();   // 当前层节点的数量
            min_distance ++;

            while (level_size > 0) {
                auto [r, c] = firstIslandQueue.front();
                firstIslandQueue.pop();

                for (int k = 0; k < directions.size() - 1; k++) {
                    // 计算新位置
                    x = r + directions[k];
                    y = c + directions[k + 1];

                    // 检查越界
                    if (x < 0 || x >= m || y < 0 || y >= n) {
                        continue;
                    }
                    // 检查是否还在第一个岛屿陆地，或者是已经遍历过的海洋位置
                    if (A[x][y] == 2) {
                        continue;
                    }
                    // 检查是否到达了第二个岛屿
                    if (A[x][y] == 1) {
                        return min_distance;
                    }
                    // 将当前位置加入 queue，并假设为第一个岛屿的陆地
                    firstIslandQueue.push({x, y});
                    A[x][y] = 2;
                }

                level_size --;
            }

        }

        return 0;
    }

private:
    vector<int> directions {-1, 0, 1, 0, -1};

    // 这里 DFS 采用：不管三七二十一先递归四个方向，然后再在下一层检查越界问题
    void dfs(vector<vector<int>> &A, int i, int j, int m, int n, queue<pair<int, int>> &firstIslandQueue) {
        // 越界检查
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return;
        }
        // 陆地检查
        if (A[i][j] == 0) {
            // 将边界海洋位置加入 queue
            firstIslandQueue.push({i, j});
            return;
        }
        // 已加入 queue 检查
        if (A[i][j] == 2) {
            return;
        }

        // 将第一个岛屿陆地置位特殊位，加入 queue
        A[i][j] = 2;

        // 遍历四个方向
        for (int k = 0; k < directions.size() - 1; k++) {
            dfs(A, i + directions[k], j + directions[k + 1], m, n, firstIslandQueue);
        }
    }

};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
// 注：这个解法与参考中的解法完全相同
// 与 Soln_1 的不同点在于：
//      1. 起点稍有不同
//      2. 由于 1，所以 Soln_1 在 BFS 时是在外层 while 循环的结尾才递增 min_distance，而该解法由于上来就是 0 位置（海洋位置），所以是外层 while 循环的开头就递增 min_distance
// 思路：先找到第一块岛屿，然后将第一块岛屿置为特殊位 (2)，并将所有第一块岛屿的边界陆地所连接的海洋位置加入 queue，然后以所有第一块岛屿的边界陆地所连接的海洋位置为 root 节点起点，开始 BFS 搜索，直至搜索到第二块岛屿
