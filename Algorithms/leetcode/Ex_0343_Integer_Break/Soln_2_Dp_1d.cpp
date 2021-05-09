#include <vector>

using std::vector;
using std::max;

class Solution_2 {
public:
    int integerBreak(int n) {
        // dp[i] 表示将正整数 i 拆分成至少两个正整数的和之后，这些正整数的最大乘积
        vector<int> dp (n + 1, 0);

        // base cases
        dp[0] = 0;  // 0 不是正整数
        dp[1] = 0;  // 1 没办法拆分成两个正整数

        // 开始填数组
        for (int i = 2; i <= n; i++) {
            int curMax = 0;     // 记录当前 i 拆分成 j 和 i-j 后的正整数的最大乘积
            
            for (int j = 1; j < i; j++) {
                // 一共有两种拆分方法：
                //  case 1: i 拆分为 j 和 i-j 后，i-j 不再继续拆分，这种情况所有 i 拆分后的正整数乘积为  ->  j * (i-j)
                //  case 2: i 拆分为 j 和 i-j 后，i-j 继续拆分，由于 dp[i-j] 记录的是 i-j 拆分正整数后的最大乘积，所以这种情况所有 i 拆分后的正整数乘积为  ->  j * dp[i-j]
                int case_1 = j * (i - j);
                int case_2 = j * dp[i-j];

                // 状态转移方程
                curMax = max(curMax, max(case_1, case_2));
            }

            dp[i] = curMax;
        }

        return dp[n];

    }
};

// 参考题解：https://leetcode-cn.com/problems/integer-break/solution/zheng-shu-chai-fen-by-leetcode-solution/
// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
// 设 N = n
// time complexity: O(N ^ 2)
// space complexity: O(N)
