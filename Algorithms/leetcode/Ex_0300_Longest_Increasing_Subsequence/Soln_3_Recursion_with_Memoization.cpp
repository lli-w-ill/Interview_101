#include <vector>
#include <algorithm>

using std::vector;
using std::max;

class Solution_3 {
public:
    int lengthOfLIS(vector<int>& nums) {        
        // memo[i][j] 代表 nums[i] as previous element considered to be included/not included in the current LIS, with nums[j] as the current element to be considered/not considered in the current LIS
        vector<vector<int>> memo (
            nums.size() + 1, 
            vector<int> (nums.size(), -1));

        int res =  lengthOfLIS(nums, nums.size(), -1, 0, memo);
        return res;
    }

private:
    int lengthOfLIS(vector<int>& nums, int size, int preIdx, int curIdx, vector<vector<int>> &memo) {
        // base case
        if (curIdx == size) {
            return 0;
        }
        if (memo[preIdx + 1][curIdx] != -1) {
            // 已计算过最优解
            return memo[preIdx + 1][curIdx];
        }

        // 选上当前数字的 LIS
        int selectCurNum = 0;
        if (preIdx < 0 || nums[curIdx] > nums[preIdx]) {
            selectCurNum = 1 + lengthOfLIS(nums, size, curIdx, curIdx + 1, memo);
        }

        // 不选上当前数字的 LIS
        int notSelectCurNum = lengthOfLIS(nums, size, preIdx, curIdx + 1, memo);

        // 记住结果，避免重复计算该子问题
        memo[preIdx + 1][curIdx] = max(selectCurNum, notSelectCurNum);

        return memo[preIdx + 1][curIdx];
    }
};

// 参考题解：https://leetcode.com/problems/longest-increasing-subsequence/solution/

