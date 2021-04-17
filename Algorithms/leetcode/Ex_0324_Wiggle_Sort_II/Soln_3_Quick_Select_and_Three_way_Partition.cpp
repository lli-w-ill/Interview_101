#include <vector>
#include <algorithm>

using std::vector;
using std::nth_element;
using std::swap;

class Solution_3 {
public:
    void wiggleSort(vector<int>& nums) {
        int size = nums.size();
        if (size == 0 || size == 1) {
            return;
        }

        auto midptr = nums.begin() + size / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;

        // 3-way-partition
        int i = 0;
        int j = 0;
        int k = size - 1;
        while (j < k) {
            if (nums[j] > mid) {
                swap(nums[j], nums[k]);
                k --;
            } else if (nums[j] < mid) {
                swap(nums[j], nums[i]);
                i ++;
                j ++;
            } else {
                j ++;
            }
        }

        if (size % 2 == 1) {
            midptr ++;
        }

        vector<int> temp1 (nums.begin(), midptr);
        vector<int> temp2 (midptr, nums.end());
        for (int i = 0; i < temp1.size(); i++) {
            nums[i * 2] = temp1[temp1.size() - 1 - i];
        }   
        for (int i = 0; i < temp2.size(); i++) {
            nums[i * 2 + 1] = temp2[temp2.size() - 1 - i];
        }
    }
};


// 参考题解（非常推荐）：https://leetcode-cn.com/problems/wiggle-sort-ii/solution/yi-bu-yi-bu-jiang-shi-jian-fu-za-du-cong-onlognjia/
// 快速选择算法（Quick Select）实现参考：http://www.noteanddata.com/classic-algorithm-quick-select.html
// nth_element 参考：https://www.cplusplus.com/reference/algorithm/nth_element/?kw=nth_element

