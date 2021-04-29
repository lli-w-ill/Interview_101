#include <vector>
#include <unordered_map>
#include <set>

using std::vector;
using std::unordered_map;
using std::set;

class Tle_2 {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        int minHeight = n;
        vector<int> minRoots;

        // 给每个节点建立邻接节点列表
        unordered_map<int, vector<int>> adjacencyNodes;
        for (const auto &e : edges) {
            adjacencyNodes[e[0]].push_back(e[1]);
            adjacencyNodes[e[1]].push_back(e[0]);
        }
        
        // 尝试让每个数字当根节点，并计算树的高度
        for (int i = 0; i < n; i++) {
            int height = 1;     // 当前高度 = 根节点一个
            // 初始化 queue
            queue<int> level;
            level.push(i);
            // 初始化走过的节点集 
            set<int> visited {i};    // 记录当前已经访问过的节点数，用于停止循环
            while (visited.size() < n) {
                int size = level.size();
                while (size > 0) {
                    int cur = level.front();
                    level.pop();

                    // 在 edges 中包含 cur 的边
                    for (const int &neighborNode : adjacencyNodes[cur]) {
                        if (!visited.count(neighborNode)) {
                            level.push(neighborNode);
                            visited.insert(neighborNode);
                        }
                    }

                    size --;
                }

                height ++;
            }

            if (height < minHeight) {
                // 更新最小高度
                minHeight = height;
                // 更新最小高度的根节点集
                minRoots.clear();
                minRoots.push_back(i);
            } else if (height == minHeight) {
                minRoots.push_back(i);
            }
        }

        return minRoots;
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
// 思路：从 0 ~ n-1 每个点分别run BFS，求出最少次数能遍历到所有点的起始节点
//
// 54 / 68 个通过测试用例

