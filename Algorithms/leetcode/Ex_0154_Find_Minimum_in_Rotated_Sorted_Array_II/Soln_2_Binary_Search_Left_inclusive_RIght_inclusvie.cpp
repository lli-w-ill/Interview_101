#include <vector>

using std::vector;

class Solution_2 {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        int left = 0;
        int right = size - 1;   // 该解法采用「左闭右闭」原则
        int mid;
        int min = nums[0];  // 题目保证一定有一个元素

        while (left <= right) {
            mid = left + (right - left) / 2;
            min = std::min(min, nums[mid]);

            if (nums[mid] == nums[left]) {
                // 无法判断当前旋转点在哪一边，右移一位左指针
                // 注：由于这个 if 条件，给我感觉如果 nums 中绝大多数都是同一个数字的话，时间复杂度将会是 O(N)，而不是 O(logN)
                // 如何提高效率：详见 Soln_3 递归解法
                left ++;
            } else if (nums[mid] <= nums[right]) {
                // nums[mid ... right] 是递增的，那么比 nums[mid] 更小的值一定在 nums[left ... mid-1]
                right = mid - 1;
            } else {
                // 旋转点在 nums[mid ... right] 中，那么比 nums[mid] 更小的值一定在 nums[mid+1 ... right]
                left = mid + 1;
            }
        }

        return min;
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394

