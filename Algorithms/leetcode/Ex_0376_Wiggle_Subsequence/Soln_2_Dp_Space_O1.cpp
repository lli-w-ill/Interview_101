#include <vector>

using std::vector;
using std::max;

class Solution_2 {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int size = nums.size();
        
        if (size == 0) {
            return 0;
        }

        int up = 1;
        int down = 1;

        // 开始填表
        for (int i = 1; i < size; i++) {
            if (nums[i] > nums[i-1]) {
                up = down + 1;
            } else if (nums[i] < nums[i-1]) {
                down = up + 1;
            }
        }

        return max(up, down);
    }
};

// 参考题解（非常推荐，图解很清楚）：https://leetcode-cn.com/problems/wiggle-subsequence/solution/tan-xin-si-lu-qing-xi-er-zheng-que-de-ti-jie-by-lg/
