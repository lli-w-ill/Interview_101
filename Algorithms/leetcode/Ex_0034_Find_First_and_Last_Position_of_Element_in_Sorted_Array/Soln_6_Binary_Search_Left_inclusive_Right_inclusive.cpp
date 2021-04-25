#include <vector>

using std::vector;

class Solution_6 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return vector<int> {-1, -1};
        }
        int lower = lowerBound(nums, target);
        int upper = upperBound(nums, target);
        // cout << lower << " " << upper << endl;

        if (lower < 0 || lower == nums.size() || nums[lower] != target) {
            return vector<int> {-1, -1};
        }
        return vector<int> {lower, upper};
    }

private:
    // 找 target 的开始位置下标
    // 这个解法采用「左闭右闭」原则，即 [l, r]
    int lowerBound(vector<int> &nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (nums[mid] > target) {
                r = mid - 1;    // 下次将会在 [l, mid - 1] 范围寻找
            } else if (nums[mid] < target) {
                l = mid + 1;    // 下次将在 [mid + 1, r] 范围寻找
            } else if (nums[mid] == target) {
                r = mid;        // 下次将会在 [l, mid] 范围寻找
            }
        }
        // return l;
        return r;    // 返回 r 也可以
    }

    // 找 target 的结束位置的下标
    // 这个解法采用「左闭右闭」原则，即 [l, r]
    int upperBound(vector<int> &nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int mid;
        while (l < r - 1) {     // 这里 -1 是因为当 l, r 相邻如 [..., target, target, ...] 或 [..., target, non-target, ...] 时，新一轮的 mid 还是 l，所以会无限循环
            mid = l + (r - l) / 2;
            if (nums[mid] < target) {
                l = mid + 1;    // 下次将在 [mid + 1, r] 范围寻找
            } else if (nums[mid] > target) {
                r = mid - 1;    // 下次将在 [l, mid - 1] 范围寻找
            } else if (nums[mid] == target) {
                l = mid;        // 下次将在 [mid, r] 范围寻找
            }
        }
        if (nums[r] != target) {
            return l;
        } else {
            return r;
        }
    }

};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
