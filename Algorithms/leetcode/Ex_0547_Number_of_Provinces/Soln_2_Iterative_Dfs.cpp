#include <vector>
#include <stack>

using std::vector;
using std::stack;

class Solution_2 {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();     // 每一行（列）代表一个节点
        int count = 0;  // circle 数量
        vector<bool> visited(n, false);
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                stack<int> stack;   // 记录当前朋友圈正在访问的朋友
                stack.push(i);

                while (!stack.empty()) {
                    int top = stack.top();
                    stack.pop();

                    visited[top] = true;
                    for (int k = 0; k < n; k++) {
                        if (isConnected[top][k] == 1 && !visited[k]) {
                            stack.push(k);
                        }
                    }
                }

                count ++;
            }
        }

        return count;
    }

};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394

