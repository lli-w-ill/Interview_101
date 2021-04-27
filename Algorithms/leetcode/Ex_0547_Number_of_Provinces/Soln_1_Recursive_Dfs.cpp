#include <vector>

using std::vector;

class Solution_1 {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();     // 每一行（列）代表一个节点
        int count = 0;
        vector<bool> visited(n, false);
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(isConnected, i, n, visited);
                count ++;
            }
        }

        return count;
    }

private:
    void dfs(vector<vector<int>> &isConnected, int i, int n, vector<bool> &visited) {
        visited[i] = true;
        for (int k = 0; k < n; k++) {
            // 这里条件没有限制『自己和自己是朋友』，即 i == k，但是因为 visited 本轮会将自己设为 true，所以是没有问题的
            if (isConnected[i][k] == 1 & !visited[k]) {
                dfs(isConnected, k, n, visited);
            }
        }
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
