#include <vector>

using std::vector;

class Solution_3 {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;    // 这里使用「左闭右闭」原则
        int mid;

        while (left <= right) {
            mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return true;
            }
            if (nums[mid] == nums[left]) {
                // 无法判断 nums[left ... mid] 全部是相同的元素
                // 右移一位左指针，继续二分查找
                left ++;
            } else if (nums[mid] <= nums[right]) {
                // nums[mid ... right] 是递增的
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else if (nums[mid] > nums[right]) {
                // 说明旋转点在右端，那么左一半 (nums[left ... mid]) 一定是递增的
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }

        return false;
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394

