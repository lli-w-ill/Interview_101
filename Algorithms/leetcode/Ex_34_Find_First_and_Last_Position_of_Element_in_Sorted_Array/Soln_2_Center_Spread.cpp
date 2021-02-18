#include <vector>

using std::vector;

class Solution_2 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> res;
        int find = binarySearch(nums, target, 0, len - 1);
        if (find == -1) {
            res.push_back(-1);
            res.push_back(-1);
        } else {
            int start = find;
            int end = find;
            // 向左延伸，直到下标越界或者nums[start] != target
            while (start >= 0 && nums[start] == target) {
                start -= 1;
            }
            if (start == -1) {
                res.push_back(0);
            } else {
                res.push_back(start + 1);
            }
            // 向右延伸，直到下标越界或者nums[end] != target
            while (end < len && nums[end] == target) {
                end += 1;
            }
            if (end == len) {
                res.push_back(len - 1);
            } else {
                res.push_back(end - 1);
            }
        }
        return res;
    }

private:
    int binarySearch(vector<int> &nums, int target, int lo, int hi) {
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                hi = mid - 1;
            } else if (nums[mid] < target) {
                lo = mid + 1;
            }
        }
        return -1;
    }
};

// 注：最坏时间复杂度依然是O(n)
