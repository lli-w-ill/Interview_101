#include <vector>

using std::vector;

class Solution_1 {
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

        return binarySearch(nums, 0, size-1, size);
    }

private:
    int binarySearch(vector<int> &nums, int l, int r, int size) {
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (mid == 0 || mid == size-1) {
                // 两端情况
                // 左极端
                if (mid == 0 && nums[mid] > nums[mid+1]) {
                    return mid;
                } else {
                    l = mid + 1;
                }

                // 右极端
                if (mid == size-1 && nums[size-1] > nums[size-2]) {
                    return mid;
                } else {
                    r = mid - 1;
                }
            } else {
                // 中间情况
                if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) {
                    // 峰值
                    return mid;
                } else if (nums[mid] > nums[mid-1] && nums[mid] < nums[mid+1]) {
                    // 升序情况，在右侧继续寻找
                    l = mid + 1;
                } else if (nums[mid] < nums[mid-1] && nums[mid] > nums[mid+1]) {
                    // 降序情况，在左侧继续寻找
                    r = mid - 1;
                } else if (nums[mid] < nums[mid-1] && nums[mid] < nums[mid+1]) {
                    // 谷值，在任意一侧寻找
                    r = mid - 1;
                }
            }
        }

        return l;
    }
};
