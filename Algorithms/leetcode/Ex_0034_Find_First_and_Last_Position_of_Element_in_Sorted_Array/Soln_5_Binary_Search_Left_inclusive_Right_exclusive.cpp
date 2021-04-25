#include <vector>

using std::vector;

class Solution_5 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return vector<int> {-1, -1};
        }
        int lower = lowerBound(nums, target);
        int upper = upperBound(nums, target) - 1;   // 这里 -1 的原因是：upperbound 其实是找的是 target结束位置的下一个位置，即「target序列后第一个不是target值的下标」，所以最后结果-1 才是target序列的结束位置
        
        if (lower == nums.size() || nums[lower] != target) {
            return vector<int> {-1, -1};
        }
        return vector<int> {lower, upper};
    }

private:
    // 找 target 的开始位置下标
    // 这个解法采用「左闭右开」原则，即 [l, r)
    int lowerBound(vector<int> &nums, int target) {
        int l = 0;
        int r = nums.size();    // 右开，所以没有-1
        int mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (nums[mid] > target) {
                r = mid;    // 注意：没有-1，因为是右开，下次将会在 [l, mid) 范围寻找
            } else if (nums[mid] < target) {
                l = mid + 1;    // 下次将在 [mid + 1, r) 范围寻找
            } else if (nums[mid] == target) {
                r = mid;    // 注意：没有-1，因为是右开，下次将会在 [l, mid) 范围寻找
            }
        }
        // return l;
        return r;    // 返回 r 也可以
    }

    // 找 target 的结束位置的下一个位置的下标
    // 这个解法采用「左闭右开」原则，即 [l, r)
    int upperBound(vector<int> &nums, int target) {
        int l = 0;
        int r = nums.size();
        int mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (nums[mid] < target) {
                l = mid + 1;    // 注意：没有+1，因为左闭右开，下次将在 [mid, r) 范围寻找
            } else if (nums[mid] > target) {
                r = mid;
            } else if (nums[mid] == target) {
                l = mid + 1;    // 下次将在 [mid + 1, r) 范围寻找
            }
        }
        // return l;
        return r;   // 返回 r 也可以
    }

};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
