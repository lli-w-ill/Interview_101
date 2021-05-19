#include <vector>

using std::vector;
using std::max;

class Solution_1 {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int size = pairs.size();

        // 首先根据 pairs[_][0] 升序排序 pairs，然后按照 pairs[_][1] 升序排序 pairs
        sort(pairs.begin(), pairs.end(), [](vector<int> &v1, vector<int> &v2) -> bool {
            if (v1[0] < v2[0]) {
                return true;
            } else if (v1[0] > v2[0]) {
                return false;
            } else {
                return v1[1] < v2[1];
            }
        });

        // dp[i] 表示 pairs[0 ... i-1] 中所有 pairs 的最长数对链
        vector<int> dp (size + 1, 0);
        // base cases
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= size; i++) {
            dp[i] = 1;  // 至少自己能够组成长度为 1 的对链
            for (int j = 1; j < i; j++) {
                if (pairs[j-1][1] < pairs[i-1][0]) {
                    // 状态转移方程
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[size];

    }
};

// 设 N = pairs.size()
// time complexity: O(N^2)
// space complexity: O(N)
