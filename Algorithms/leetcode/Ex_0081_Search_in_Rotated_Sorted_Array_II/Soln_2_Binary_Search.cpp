#include <vector>

using std::vector;

class Solution_2 {
public:
    bool search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (target == nums[mid]) {
                return true;
            }
            if (nums[lo] == nums[hi]) {
                // 比较Ex33题，需要加上这个if判断
                lo += 1;
                continue;
            }
            if (nums[lo] <= nums[mid]) {
                // nums[lo ... mid] 是升序（没有旋转）
                // nums[mid+1 ... hi] 是有旋转的
                if (target >= nums[lo] && target < nums[mid]) {
                    // target 可能在 nums[lo ... mid-1] 之间
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            } else {
                // nums[lo ... mid] 是有旋转的
                // nums[mid+1 ... hi] 是升序（没有旋转）
                if (target > nums[mid] && target <= nums[hi]) {
                    // target 可能在 nums[mid+1 ... hi] 之间
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
        }
        return false;
    }
};

// 注：这个解法是伪二分法，因为15-19行的if判断，在极端情况，nums中都是相同值的情况下，时间复杂度依然是O(n)，与线性搜索一样
// 另一个相似的解法，参考：https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/solution/zai-javazhong-ji-bai-liao-100de-yong-hu-by-reedfan/
