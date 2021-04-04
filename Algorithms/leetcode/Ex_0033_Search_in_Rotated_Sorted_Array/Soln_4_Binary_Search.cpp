#include <vector>

using std::vector;

class Solution_4 {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[lo] <= nums[mid]) {
                // 说明 nums[lo ... mid] 是升序的（没有旋转），之所以有等于号，因为lo和mid可能相等
                if (target >= nums[lo] & target < nums[mid]) {
                    // target 可能在 nums[lo ... mid-1] 之间
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            } else {
                // 说明 nums[lo ... mid] 有旋转，表示 nums[mid+1 ... hi] 是升序的（没有旋转）
                if (target > nums[mid] && target <= nums[hi]) {
                    // target 可能在 nums[mid+1 ... hi] 之间
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
        }
        return -1;
    }
};

// 参考（精选评论angon823）：https://leetcode-cn.com/problems/search-in-rotated-sorted-array/solution/ji-jian-solution-by-lukelee/
// 参考：https://leetcode-cn.com/problems/search-in-rotated-sorted-array/solution/ji-bai-liao-9983de-javayong-hu-by-reedfan/
