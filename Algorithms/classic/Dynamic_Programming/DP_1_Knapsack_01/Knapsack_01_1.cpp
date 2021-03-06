#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;
using std::max;

int knapsack01 (const vector<int> &weights, const vector<int> &values, int N, int W) {
    // dp[i][j] 表示前 i 件物品，当背包容量为 j 时，可以装下的最大物品价值的和
    // 初始值第一行、第一列均为 0
    vector<vector<int>> dp (N + 1, vector<int> (W + 1, 0));

    for (int i = 1; i <= N; i++) {
        // 获得当前物品的重量 (w) 和价值 (v)
        int w = weights[i-1];
        int v = values[i-1];
        for (int j = 1; j <= W; j++) {
            if (j >= w) {
                // 如果当前背包可以装下当前的物品，那么有两种选择
                //  1. 不装当前物品 i，最大价值不变 -> dp[i-1][j]
                //  2. 装当前物品 i，最大价值为    -> dp[i-1][j-w] + v
                // 状态转移方程
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w] + v);
            } else {
                // 如果当前背包不可以装下当前的物品，那么只有一种选择，即上述的第 1 种
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[N][W];
}

int main() {
    // 测试用例 1
    vector<int> weights1 {2, 7, 3, 4, 8, 5, 8, 6, 4, 16};       // 每件物品的重量
    vector<int> values1 {15, 25, 8, 9, 15, 9, 13, 9, 6, 14};    // 每件物品的价值
    int N1 = 10;        // 总物品数量
    int W1 = 34;        // 总背包容量
    cout << "测试用例 1：背包总容量 = " << W1 << "，可以装下的最大物品价值的和 = " << knapsack01(weights1, values1, N1, W1) << endl;     // 正确结果：87
    

    // 测试用例 2
    vector<int> weights2 {2, 8, 4, 4, 8, 7, 8, 5, 16, 16};
    vector<int> values2 {15, 25, 9, 9, 15, 12, 12, 6, 14, 9};
    int N2 = 10;
    int W2 = 34;
    cout << "测试用例 2：背包总容量 = " << W2 << "，可以装下的最大物品价值的和 = " << knapsack01(weights2, values2, N2, W2) << endl;     // 正确结果：85


    // 测试用例 3
    vector<int> weights3 {4, 5, 7, 2, 8, 3, 6, 1, 10, 9};
    vector<int> values3 {25, 14, 15, 4, 14, 5, 8, 1, 10, 2};
    int N3 = 10;
    int W3 = 34;
    cout << "测试用例 3：背包总容量 = " << W3 << "，可以装下的最大物品价值的和 = " << knapsack01(weights3, values3, N3, W3) << endl;     // 正确结果：82


    // 测试用例 4
    vector<int> weights4 {4, 5, 7, 2, 8, 3, 9, 6, 1, 10};
    vector<int> values4 {25, 14, 15, 4, 14, 5, 14, 8, 1, 10};
    int N4 = 10;
    int W4 = 34;
    cout << "测试用例 4：背包总容量 = " << W4 << "，可以装下的最大物品价值的和 = " << knapsack01(weights4, values4, N4, W4) << endl;     // 正确结果：83

    return 0;
}

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
// 01背包问题测试数据：https://blog.csdn.net/miscclp/article/details/8787732
// 
// 设 N 为物品的数量，W 为背包的容量
// time complexity: O(N * W)
// space complexity: O(N * W)
