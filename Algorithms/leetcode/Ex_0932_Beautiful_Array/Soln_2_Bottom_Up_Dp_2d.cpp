#include <vector>

using std::vector;

class Solution_2 {
public:
    vector<int> beautifulArray(int n) {
        // dp[i] 表示分治解法中 f(i) 的值
        vector<vector<int>> dp;

        // base case: 
        // n = 0 时，什么都没有
        // n = 1 时，f(1) 的结果是 [1]
        dp.push_back(vector<int> {});
        dp.push_back(vector<int> {1});

        for (int i = 2; i <= n; i++) {
            vector<int> curBeautifulArr;

            // 填充奇数部分（和正中间的数）
            // 规则：2 * ___ - 1
            for (int &x : dp[(i + 1) / 2]) {
                curBeautifulArr.push_back(2 * x - 1);
            }

            // 填充偶数部分
            // 规则：2 * ___
            for (int &x : dp[i/2]) {
                curBeautifulArr.push_back(2 * x);
            }

            dp.push_back(curBeautifulArr);
        }

        return dp[n];

    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
// 参考题解（非常推荐）：https://leetcode-cn.com/problems/beautiful-array/solution/c-fen-zhi-fa-dai-tu-pian-jie-shi-by-avphn4vwuo/
