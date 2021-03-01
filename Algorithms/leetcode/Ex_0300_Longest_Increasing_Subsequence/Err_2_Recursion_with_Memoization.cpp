#include <vector>
#include <algorithm>

using std::vector;
using std::max;

class Err_2 {
public:
    int lengthOfLIS(vector<int>& nums) {        
        // 在下标 0 插入一个 INT_MIN，为了递归函数中 preIdx 不用 +1
        nums.insert(nums.begin(), INT_MIN);

        // memo[i][j] 代表 nums[i] as previous element considered to be included/not included in the current LIS, with nums[j] as the current element to be considered/not considered in the current LIS
        vector<vector<int>> memo (
            nums.size(), 
            vector<int> (nums.size(), -1));

        int res =  lengthOfLIS(nums, nums.size(), 0, 1, 0, memo);

        for (vector<int> &v : memo) {
            for (int num : v) {
                cout << num << " ";
            }
            cout << endl;
        }
        cout << endl;

        return res;
    }

private:
    int lengthOfLIS(vector<int>& nums, int size, int preIdx, int curIdx, int longest, vector<vector<int>> &memo) {
        // base case
        if (curIdx == size) {
            return longest;
        }
        if (memo[preIdx][curIdx] != -1) {
            // 已计算过最优解
            return memo[preIdx][curIdx];
        }

        // 选上当前数字的 LIS
        int selectCurNum = 0;
        if (nums[curIdx] > nums[preIdx]) {
            selectCurNum = lengthOfLIS(nums, size, curIdx, curIdx + 1, longest + 1, memo);
        }

        // 不选上当前数字的 LIS
        int notSelectCurNum = lengthOfLIS(nums, size, preIdx, curIdx + 1, longest, memo);

        // 记住结果，避免重复计算该子问题
        memo[preIdx][curIdx] = max(selectCurNum, notSelectCurNum);

        return memo[preIdx][curIdx];
    }
};

// 参考算法：https://leetcode.com/problems/longest-increasing-subsequence/solution/
// 错误测试用例：[3,5,6,2,5,4,19,5,6,7,12]
// 期待输出：6
// 实际输出：5
