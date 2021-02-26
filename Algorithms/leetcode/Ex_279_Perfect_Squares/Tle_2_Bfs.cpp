#include <vector>
#include <queue>

using std::vector;
using std::queue;

class Tle_2 {
public:
    int numSquares(int n) {
        queue<vector<int>> queue;
        // 第一个元素表示现在还剩多少 (remain)
        // 第二个元素表示目前已经用了多少个perfect square numbers（相当于bfs节点的深度）
        queue.push(vector<int> {n, 0});
        int depth = 0;
        while (!queue.empty()) {
            vector<int> v = queue.front();
            queue.pop();
            for (int i = 1; i * i <= v[0]; i++) {
                if (v[0] == i * i) {
                    // 当 v[0] + i 就是 n，说明已经找到最少的perfect square numbers了
                    return v[1] + 1;
                }
                queue.push(vector<int> {v[0] - i * i, v[1] + 1});
            }
        }
        return -1;
    }
};
