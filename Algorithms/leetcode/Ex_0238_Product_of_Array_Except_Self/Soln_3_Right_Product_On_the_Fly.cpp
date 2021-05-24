#include <vector>

using std::vector;

class Solution_3 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();

        if (size == 0) {
            return vector<int> {};
        }

        // left[i] 表示 nums[0 ... i-1] 相乘的“前缀和”
        vector<int> left (size, 1);
        // 从左向右填充 left
        for (int i = 1; i < size; i++) {
            left[i] = left[i-1] * nums[i-1];
        }

        // 从右向左，一遍动态计算 right[i]，一遍填充结果数组
        vector<int> res (size, 0);
        int right = 1;
        for (int i = size - 1; i >= 0; i--) {
            res[i] = left[i] * right;

            right *= nums[i];
        }

        return res;

    }
};
