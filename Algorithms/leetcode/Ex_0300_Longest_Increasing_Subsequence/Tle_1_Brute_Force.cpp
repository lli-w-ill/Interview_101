#include <vector>
#include <algorithm>

using std::vector;
using std::max;

class Tle_1 {
public:
    int lengthOfLIS(vector<int>& nums) {
        return lengthOfLIS(nums, nums.size(), INT_MIN, 0, 0);
    }

private:
    int lengthOfLIS(vector<int>& nums, int size, int preVal, int curIdx, int longest) {
        // base case
        if (curIdx == size) {
            return longest;
        }
        
        // 选上当前数字的 LIS
        int selectCurNum = 0;
        if (nums[curIdx] > preVal) {
            selectCurNum = lengthOfLIS(nums, size, nums[curIdx], curIdx + 1, longest + 1);
        }

        // 不选上当前数字的 LIS
        int notSelectCurNum = lengthOfLIS(nums, size, preVal, curIdx + 1, longest);

        return max(selectCurNum, notSelectCurNum);
    }
};

// 时间复杂度：O(2^n)
// 空间复杂度：O(n^2)
// 算法思路参考：https://leetcode.com/problems/longest-increasing-subsequence/solution/
