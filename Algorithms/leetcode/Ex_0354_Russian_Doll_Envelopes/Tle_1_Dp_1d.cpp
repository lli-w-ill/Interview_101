#include <vector>
#include <algorithm>

using std::vector;
using std::sort;
using std::max;

class Tle_1 {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int size = envelopes.size();
        int res = 0;        // 记录最多套娃数

        // 按照 w 升序排序
        sort(envelopes.begin(), envelopes.end(), [](vector<int> v1, vector<int> v2) -> bool {
            return v1[0] < v2[0];       // 这里不要有 = 号
        });

        // dp[i] 表示 envelops[0 ... i] 的最多套娃数
        vector<int> dp (size, 1);

        for (int i = 0; i < size; i++) {
            vector<int> v = envelopes[i];

            for (int j = 0; j < i; j++) {
                vector<int> temp = envelopes[j];
                if (v[0] > temp[0] && v[1] > temp[1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            res = max(res, dp[i]);
        }

        return res;

    }
};

// 相关题目：Ex.300
// 设 N = envelops.size()
// time complexity: O(N ^ 2)
// space complexity: O(N)
