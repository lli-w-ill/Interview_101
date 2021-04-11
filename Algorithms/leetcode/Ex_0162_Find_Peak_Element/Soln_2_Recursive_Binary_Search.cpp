#include <vector>

using std::vector;

class Solution_2 {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        int size = nums.size();
        // 对只包含一个元素需要特判
        if (size == 1) {
            return 0;
        }
        // 对两端元素需要特判
        if (nums[0] > nums[1]) {
            return 0;
        }
        if (nums[size-1] > nums[size-2]) {
            return size - 1;
        }

        return binarySearch(nums, 1, size-2);
    }

private:
    int binarySearch(vector<int> &nums, int l, int r) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) {
                // 峰值
                return mid;
            } else {
                int leftPeakIndex = binarySearch(nums, l, mid-1);
                int rightPeakIndex = binarySearch(nums, mid+1, r);
                return leftPeakIndex != 0 ? leftPeakIndex : rightPeakIndex;
            }
        }
        return 0;
    }
};

// 参考之前账号提交记录

