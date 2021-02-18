#include <vector>
#include <algorithm>    // sort

using std::vector;
using std::sort;

class Solution_1 {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;    // 报错所有结果
        vector<int> cur;    // 保存每次的结果
        if (candidates.empty()) {
            return res;
        }
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0, candidates.size(), 0, target, cur, res);
        return res;
    }

private:
    void backtrack(vector<int> &nums, int startIdx, int endIdx, int curSum, int target, vector<int> &curNum, vector<vector<int>> &res) {
        if (curSum == target) {
            res.push_back(curNum);
            return;
        }
        if (curSum > target) {
            // 剪枝 pruning
            return;
        }
        for (int i = startIdx; i < endIdx; i++) {
            curNum.push_back(nums[i]);
            backtrack(nums, i, endIdx, curSum + nums[i], target, curNum, res);
            curNum.pop_back();   // 回溯
        }
    }
};

// 注：将startIdx和endIdx当作参数是为了去重。例如：(2,2,3), (2,3,2), (3,2,2) ...
