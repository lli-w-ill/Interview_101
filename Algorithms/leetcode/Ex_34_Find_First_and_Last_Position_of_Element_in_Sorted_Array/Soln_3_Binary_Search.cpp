#include <vector>

using std::vector;

class Solution_3 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> res;
        int find = binarySearch(nums, target, 0, len - 1);
        if (len == 0 || find == -1) {
            res.push_back(-1);
            res.push_back(-1);
        } else {
            int start = find; // 第一个位置
            int end = find;   // 最后一个位置
            // 在[0 ... start-1]找第一个位置
            do {
                find = binarySearch(nums, target, 0, start - 1);
                if (find != -1) {
                    start = find;
                }
            } while (find != -1 && start > 0);      // 注意如果start已经是0了，就没必要在循环了
            // 在[end+1 ... len-1]找最后一个位置
            do {
                find = binarySearch(nums, target, end + 1, len - 1);
                if (find != -1) {
                    end = find;
                }
            } while (find != -1 && end < len - 1);  // 注意如果end已经是len-1了，就没必要在循环了
            res.push_back(start);
            res.push_back(end);
        }
        return res;
    }

private:
    int binarySearch(vector<int> &nums, int target, int lo, int hi) {
        // 这里需要这两个base cases处理边缘情况
        if (hi == 0) {
            if (nums[hi] == target) {
                return 0;
            } else {
                return -1;
            }
        }
        if (lo == nums.size() - 1) {
            if (nums[lo] == target) {
                return nums.size() - 1;
            } else {
                return -1;
            }
        }
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

// 注：感觉时间复杂度是 O((logn)^2) ?? 因为每次binarySearch是O(logn)，并且在一个循环里每次调用
