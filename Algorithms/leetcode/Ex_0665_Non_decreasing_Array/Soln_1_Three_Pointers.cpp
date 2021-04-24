#include <vector>

using std::vector;

class Solution_1 {
public:
    bool checkPossibility(vector<int>& nums) {
        bool changed = false;  // 记录当前是否已经改变了一个元素
        int size = nums.size();
        if (size == 1) {
            return true;
        }
        if (nums[0] > nums[1]) {
            // 如果第一个元素大于第二个元素，则发动技能把第一个元素改为第二个元素
            nums[0] = nums[1];
            changed = true;
        }

        // 开始循环
        for (int i = 1; i < size; i++) {
            if (nums[i-1] > nums[i]) {
                // 出现了逆序
                if (changed == true) {
                    // 已经使用过了技能
                    return false;
                } else {
                    // 改变目的：把 nums[i-1] 和 nums[i] 其中之一改到尽可能地小
                    if (i - 2 >= 0) {
                        // 如果有二先驱元素的话，则比较当前值和二先驱元素
                        if (nums[i-2] > nums[i]) {
                            // 如果二先驱元素也大于当前，那只能将当前数改为 nums[i-1] 
                            // e.g. [3,4,2] -> [3,4,4]
                            nums[i] = nums[i-1];
                        } else {
                            // 如果二先驱元素不大于当前，那把前一个元素改为 nums[i]（因为当前元素更小）
                            // e.g. [2,4,3] -> [2,3,3]
                            nums[i-1] = nums[i];
                        }
                        changed = true;
                    } else {
                        // 如果没有二先驱元素的话，则都改为 nums[i-1] 的值
                        // e.g. [3,2,...] -> [3,3,...] 
                        nums[i] = nums[i-1];
                        changed = true;
                    }
                }
            }
        }

        return true;

    }
};
