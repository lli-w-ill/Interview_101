#include <vector>

using std::vector;

class Tle_2 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        int len = nums.size();
        // 思路：利用 sum( nums[start ... end] ) = sum( nums[0 ... end] ) - sum( nums[0 ... start) )
        // 首先计算所有 sum( nums[0 ... i] )
        map<int, int> cumulativeSum;
        // 当start = 0时，start-1 = -1，所以特殊加一个key
        cumulativeSum.insert(pair<int, int> (-1, 0));
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum += nums[i];
            cumulativeSum.insert(pair<int, int> (i, sum));
        }
        // 然后遍历所有开始位置 start 和结束位置 end
        for (int start = 0; start < len; start++) {
            for (int end = start; end < len; end++) {
                // 计算 sum( nums[start ... end])，检查是否等于 k
                if (cumulativeSum[end] - cumulativeSum[start - 1] == k) {
                    res += 1;
                }
            }
        }
        return res;
    }
};
