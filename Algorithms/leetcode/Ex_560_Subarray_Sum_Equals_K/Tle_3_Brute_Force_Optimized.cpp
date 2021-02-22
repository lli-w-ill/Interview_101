#include <vector>

using std::vector;

class Tle_3 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        int len = nums.size();
        for (int start = 0; start < len; start++) {
            int sum = 0;
            for (int end = start; end < len; end++) {
                // 这里由于开始位置 start 是固定的，随着结束位置 end 向末端移动，每次累加和，然后与k判断，从而这里省略了一个内层 i 循环单独计算 sum( nums[start ... end])
                sum += nums[end];
                if (sum == k) {
                    res += 1;
                }
            }
        }
        return res;
    }
};
