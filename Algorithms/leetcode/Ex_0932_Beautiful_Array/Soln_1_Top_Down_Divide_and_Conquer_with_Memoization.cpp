#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution_1 {
private:
    // memoization
    // key: N
    // value: f(N) 的所有值
    unordered_map<int, vector<int>> ump;

    vector<int> f(int N) {
        // check in memo
        if (ump.find(N) != ump.end()) {
            return ump[N];
        }

        vector<int> res (N, 0);
        int t = 0;  // 用作下标

        if (N != 1) {
            // 永远保证奇数部分在前，偶数部分在后
            // 填充奇数部分（左半部分 （+ 正中间的值））
            // 规则：将 f((N + 1) / 2) 中的值 都先乘2再减1
            for (auto x : f((N + 1) / 2)) {
                res[t++] = 2 * x - 1;
            }
            // 填充偶数部分（右半部分）
            // 规则：将 f(N/2) 中的值 都直接乘2
            for (auto x : f(N / 2)) {
                res[t++] = 2 * x;
            }
        } else {
            res[0] = 1;
        }

        // 保存结果
        ump[N] = res;

        return res;
    }

public:
    vector<int> beautifulArray(int n) {
        return f(n);
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
// 参考题解（非常推荐）：https://leetcode-cn.com/problems/beautiful-array/solution/c-fen-zhi-fa-dai-tu-pian-jie-shi-by-avphn4vwuo/
