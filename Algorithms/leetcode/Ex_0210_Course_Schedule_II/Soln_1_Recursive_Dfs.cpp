#include <vector>
#include <map>
#include <list>

using std::vector;
using std::map;
using std::list;

class Solution_1 {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        init(numCourses);

        buildGraph(prerequisites);

        vector<int> reversedTopologicalOrder;    // 拓扑序列的逆序列
        for (const auto &[key, value] : adjacencyList) {    // this is supported in C++17
            // 如果已经检测到图中存在环，那么不存在一种正确的安排，返回空数组
            if (isAcyclic) {
                return vector<int> {};
            }

            // 从未访问的节点开始 dfs
            if (color[key] == WHITE) {
                dfs(key, reversedTopologicalOrder);
            }
        }

        // 有可能是最后一条边才组成的环，所以在for下面需要再检查一遍
        if (isAcyclic) {
            return vector<int> {};
        }

        // 最终结果需要翻转逆拓扑序列
        vector<int> res {reversedTopologicalOrder.rbegin(), reversedTopologicalOrder.rend()};

        return res;
    }

private:
    // key: node 的值
    // value: node 的指向的节点，即修完当前课，才能修 value 中的课
    map<int, list<int>> adjacencyList;
    // key: node 的值
    // vaule: node 的颜色（白色：未访问；灰色：正在访问；黑色：已访问）
    map<int, int> color;
    const int WHITE = 1;
    const int GRAY = 2;
    const int BLACK = 3;
    int numCourses;
    // 标识符：是否遇到了环
    bool isAcyclic;

    void init(int numCourses) {
        // 初始化 numCourses, adjacencyList
        this->numCourses = numCourses;

        for (int i = 0; i < numCourses; i++) {
            // 每个课程的邻接表初始为空列表
            adjacencyList[i] = list<int> {};
            // 颜色初始为「未访问」
            color[i] = WHITE;
        }

        isAcyclic = false;
    }

    void buildGraph(const vector<vector<int>> &prerequisites) {
        for (const vector<int> &v : prerequisites) {
            // 添加边
            // 例子：v = [1, 0]
            // 如果要修课程 1，需要先修课程 0，所以在图中，应该是从 0 -> 1 的一条边 (source -> destination)
            int source = v[1];
            int destination = v[0];
            adjacencyList[source].push_back(destination);
        }

        // 测试输出 adjacencyList
        // for (const auto &[key, value] : adjacencyList) {
        //     cout << key << " -> ";
        //     for (const auto &val : value) {
        //         cout << val << " ";
        //     }
        //     cout << endl;
        // }
    }

    void dfs(int curNode, vector<int> &reversedTopologicalOrder) {
        // 开始访问该节点，改变当前节点的颜色
        color[curNode] = GRAY;

        // 访问当前节点的孩子
        for (int neighbor : adjacencyList[curNode]) {
            if (isAcyclic) {
                return;
            }
            if (color[neighbor] == GRAY) {
                // 说明当前节点的孩子正在被访问，检测到环
                isAcyclic = true;
                return;
            } else if (color[neighbor] == BLACK) {
                continue;
            } else if (color[neighbor] == WHITE) {
                // 访问孩子节点
                dfs(neighbor, reversedTopologicalOrder);
            }
        }

        // 将当前节点设置为「已访问」
        color[curNode] = BLACK;

        reversedTopologicalOrder.push_back(curNode);
    }
};

// 参考之前账号提交记录
// range-based for loop with c++ std::map 参考：https://stackoverflow.com/questions/6963894/how-to-use-range-based-for-loop-with-stdmap
