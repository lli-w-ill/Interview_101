#include <vector>
#include <unordered_map>
#include <queue>

using std::vector;
using std::unordered_map;
using std::queue;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return vector<int> {0};
        }

        // 初始化所有节点的出度，方便追踪叶子节点
        vector<int> outDegree (n, 0);
        for (const auto &e : edges) {
            outDegree[e[0]] ++;
            outDegree[e[1]] ++;
        }

        // 初始化所有邻接节点列表
        unordered_map<int, vector<int>> adjacencyNodes;
        for (const auto &e : edges) {
            // 无向边 = 正反向两条边
            adjacencyNodes[e[0]].push_back(e[1]);
            adjacencyNodes[e[1]].push_back(e[0]);
        }

        // 将所有出度为 1（即叶子节点们）加入到最初的队列
        queue<int> level;
        for (int i = 0; i < n; i++) {
            if (outDegree[i] == 1) {
                level.push(i);
            }
        }

        // 开始从最外层 run BFS
        // 每次重新记录最外层的节点，当最后一层时记录的就是最内的节点
        vector<int> res;
        while (!level.empty()) {
            res.clear();    // 每次清空上一次记录的最外层节点集，然后记录当前 BFS 回合最外层的结果集
            int size  = level.size();
            while (size > 0) {
                int cur = level.front();
                level.pop();

                res.push_back(cur);

                // 遍历 cur 的所有邻接节点，作为 BFS 下一层的节点
                for (const int &neighbor : adjacencyNodes[cur]) {
                    outDegree[neighbor] --; // 移除 cur -> neighbor 这条边
                    // 检查移除这条边后是否 neighbor 也是叶子节点
                    if (outDegree[neighbor] == 1) {
                        // 当前 neighbor 也是叶子节点
                        level.push(neighbor);
                    }
                }

                size --;
            }
        }

        return res;
    }
};

// 参考题解（推荐）：https://leetcode-cn.com/problems/minimum-height-trees/solution/zui-rong-yi-li-jie-de-bfsfen-xi-jian-dan-zhu-shi-x/
// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
// 思路：这道题与 Ex.417 Pacific AtlanticWater Flow (Medium) 有异曲同工之妙；
// 我们的目标是找到节点集，是其中的节点用最少的步数可以遍历到全部节点（这里其实暗指「全部叶子节点」）。所以我们可以将全部叶子节点当作起点，向「中央」run BFS。每次跑完一次 BFS，将当前最外围的节点“剪掉”，最终当 queue 为空时，结果集中就是『最中心的点集』

