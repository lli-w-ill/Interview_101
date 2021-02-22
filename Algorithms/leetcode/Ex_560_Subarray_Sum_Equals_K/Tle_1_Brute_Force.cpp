#include <vector>

using std::vector;

class Tle_1 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        int len = nums.size();
        for (int start = 0; start < len; start++) {
            for (int end = start; end < len; end++) {
                // 计算 nums[start ... end] 之间的和
                int sum = 0;
                for (int i = start; i <= end; i++) {
                    sum += nums[i];
                }
                if (sum == k) {
                    res += 1;
                }
            }
        }
        return res;
    }
};
