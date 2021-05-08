#include <vector>

using std::vector;

class Solution_4 {
public:
    vector<int> countBits(int num) {
        // dp[i] 表示数字 i 一共有多少「二进制1」
        vector<int> dp (num+1, 0);

        for (int i = 1; i <= num; i++) {
            if ((i & 1) == 1) { // 注意加括号，因为优先级 = > &
                // 奇数
                dp[i] = dp[i - 1] + 1;
            } else {
                // 偶数
                dp[i] = dp[i >> 1];
            }
        }
        return dp;
    }
};

// 参考题解（非常推荐）：https://leetcode-cn.com/problems/counting-bits/solution/hen-qing-xi-de-si-lu-by-duadua/

