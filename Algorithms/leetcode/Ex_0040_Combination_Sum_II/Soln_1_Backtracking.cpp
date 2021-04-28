#include <vector>

using std::vector;

class Solution_1 {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // 先升序排序
        sort(candidates.begin(), candidates.end());

        int size = candidates.size();
        vector<vector<int>> res;
        vector<int> combo;
        vector<bool> used (size, false);
        int curSum = 0;
        backtracking(candidates, combo, res, curSum, target, 0, size, used);
        
        return res;
    }

private:
    // 这里回溯采用：不管累积和是否超过了 target，先递归，然后在下一层判断再返回的策略
    void backtracking(const vector<int> &nums, vector<int> &combo, vector<vector<int>> &res, int curSum, int trgSum, int curIdx, int size, vector<bool> &used) {
        if (curSum > trgSum) {
            return;
        }
        if (curSum == trgSum) {
            res.push_back(combo);
            return;
        }

        for (int i = curIdx; i < size; i++) {
            // 这里的条件与 Ex.47 中的解法相同
            // 当前 num[i-1] 存在，且没有被使用过 ———— 说明这一层以 nums[i-1] 为根节点的子树已经访问过了，所以不需要再在本层以相同的数字 (nums[i]) 为根访问其下面的子树了
            if (i - 1 >= 0 && nums[i-1] == nums[i] && !used[i-1]) {
                continue;
            }

            // 修改当前节点状态
            curSum += nums[i];
            combo.push_back(nums[i]);
            used[i] = true;

            // 递归子节点
            // 这里让下次递归从 i+1 开始，为了防止重复的数字组合
            backtracking(nums, combo, res, curSum, trgSum, i + 1, size, used);

            // 恢复当前节点状态
            used[i] = false;
            combo.pop_back();
            curSum -= nums[i];
        }
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394

