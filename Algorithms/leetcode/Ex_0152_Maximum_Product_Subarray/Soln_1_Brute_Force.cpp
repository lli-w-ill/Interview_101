#include <vector>

using std::vector;

class Solution_1 {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        }
        if (len == 1) {
            return nums[0];
        }
        int res = 0;
        for (int start = 0; start < len; start++) {
            int temp = 1;
            for (int end = start; end < len; end++) {
                temp *= nums[end];
                if (temp > res) {
                    res = temp;
                }
            }
        }
        return res;
    }
};

// 时间复杂度: O(n^2)
