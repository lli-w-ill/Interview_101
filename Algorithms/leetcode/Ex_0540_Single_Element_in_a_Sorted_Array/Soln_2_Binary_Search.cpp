#include <vector>

using std::vector;

class Solution_2 {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int size = nums.size();
        // 特判（没有必要做特判）
        // if (size == 1) {
        //     return nums[0];
        // }

        int left = 0;
        int right = size - 1;
        int mid;
        while (left < right) {  // 注意：这里没有 =，详见偶数下标解释
            mid = left + (right - left) / 2;

            if (mid % 2 == 0) {
                // 当前在偶数下标
                // 检查当前位和下一位数字的关系（这里不用检查越界关系，因为虽然最后一个数字的下标是偶数，但是 mid 不可能等于 size-1，因为只有当 left = right = size - 1 时，mid 才可能指向最后一个下标，但是当 left = right 时，while 条件就已经先不符合了，所以就退出了）
                if (nums[mid] == nums[mid + 1]) {
                    // 说明单一元素在右侧
                    left = mid + 2;
                } else if (nums[mid] != nums[mid + 1]) {
                    // 说明单一元素在左侧
                    right = mid;
                }
            } else {
                // 当前在奇数下标
                // 检查当前位和下一位的关系（这里不用检查越界问题，因为 size 一定是奇数，那么最后一个数字的下标就一定是偶数）
                if (nums[mid] == nums[mid + 1]) {
                    // 说明单一元素在左侧
                    right = mid - 1;
                } else if (nums[mid] != nums[mid + 1]) {
                    // 说明单一元素在右侧
                    left = mid + 1;
                }
            }
        }

        return nums[left];
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
// 单一元素出现之前：前一个偶数下标的元素 == 后一个奇数下标的元素
// 单一元素出现之后：前一个奇数下标的元素 == 后一个偶数下标的元素
