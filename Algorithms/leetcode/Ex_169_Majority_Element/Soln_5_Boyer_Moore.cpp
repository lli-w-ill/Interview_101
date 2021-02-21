#include <vector>

using std::vector;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                count = 1;
                candidate = nums[i];
            } else if (nums[i] == candidate) {
                count += 1;
            } else if (nums[i] != candidate) {
                count -= 1;
            }
        }
        return candidate;
    }
};

// 参考题解（非常推荐）：https://leetcode-cn.com/problems/majority-element/solution/duo-shu-yuan-su-by-leetcode-solution/
// 时间复杂度：O(n)
// 空间复杂度：O(1)
