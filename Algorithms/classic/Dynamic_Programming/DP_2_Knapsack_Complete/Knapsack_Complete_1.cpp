#include <vector>
#include <iostream>

using std::vector;
using std::max;
using std::cout;
using std::endl;

int knapsack_complete(const vector<int> &weights, const vector<int> &values, int N, int W) {
    // dp[i][j] 表示只用前 i 件物品，当背包容量为 j 时，可以装下的最大物品价值的和
    vector<vector<int>> dp (N + 1, vector<int> (W + 1, 0));

    for (int i = 1; i <= N; i++) {
        // 获得当前物品的重量 (w) 和价值 (v)
        int w = weights[i-1];
        int v = values[i-1];

        for (int j = 1; j <= W; j++) {
            if (j >= w) {
                // 如果当前背包可以装下当前的物品，那么有两种选择
                //  1. 不装入当前物品 i，最大价值为     -> dp[i-1][j]
                //  2. 装入一个当前物品 i，最大价值为   -> dp[i][j-w] + v（至于为什么是[i]而不是[i-1]，详见「编程指北」笔记第 53 页）
                // 状态转移方程
                dp[i][j] = max(dp[i-1][j], dp[i][j-w] + v);
            } else {
                // 如果当前背包装不下一个当前的物品了，那么只有一种选择，即上述的第 1 种
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[N][W];
}

int main() {
    // 测试用例 1
    vector<int> weights1 {3, 2, 5, 1, 6, 4};    // 每件物品的重量
    vector<int> values1 {6, 5, 10, 2, 16, 8};   // 每件物品的价值
    int N1 = 6;      // 物品总数量
    int W1 = 10;     // 背包总容量
    cout << "测试用例 1：背包总容量 = " << W1 << "，可以装下的最大物品价值的和 = " << knapsack_complete(weights1, values1, N1, W1) << endl;     // 正确结果：26


    // 测试用例 2
    vector<int> weights2 {1, 2, 3, 4};
    vector<int> values2 {2, 4, 4, 5};
    int N2 = 4;
    int W2 = 5;
    cout << "测试用例 2：背包总容量 = " << W2 << "，可以装下的最大物品价值的和 = " << knapsack_complete(weights2, values2, N2, W2) << endl;     // 正确结果：10


    // 测试用例 3
    vector<int> weights3 {4, 5, 6, 2, 2};
    vector<int> values3 {6, 4, 5, 3, 6};
    int N3 = 5;
    int W3 = 10;
    cout << "测试用例 3：背包总容量 = " << W3 << "，可以装下的最大物品价值的和 = " << knapsack_complete(weights3, values3, N3, W3) << endl;     // 正确结果：30


    // 测试用例 4
    vector<int> weights4 {3, 2, 2};
    vector<int> values4 {5, 10, 20};
    int N4 = 3;
    int W4 = 5;
    cout << "测试用例 4：背包总容量 = " << W4 << "，可以装下的最大物品价值的和 = " << knapsack_complete(weights4, values4, N4, W4) << endl;     // 正确结果：40


    // 测试数据 5
    vector<int> weights5 {2, 3, 4, 7};
    vector<int> values5 {1, 3, 5, 9};
    int N5 = 4;
    int W5 = 10;
    cout << "测试用例 5：背包总容量 = " << W5 << "，可以装下的最大物品价值的和 = " << knapsack_complete(weights5, values5, N5, W5) << endl;     // 正确结果：12

    return 0;
}

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
// 完全背包问题测试数据参考如下网站：
// https://blog.csdn.net/wumuzi520/article/details/7014830
// https://blog.csdn.net/SCS199411/article/details/98782356
// http://littleroach110.net/2017/02/18/Complete-Knapsack.html
// https://segmentfault.com/a/1190000012829866
//
// 设 N 为物品的数量，W 为背包容量
// time complexity: O(N * W)
// space complexity: O(N * W)
