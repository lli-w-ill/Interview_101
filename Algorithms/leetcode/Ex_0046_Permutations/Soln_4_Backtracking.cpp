#include <vector>

using std::vector;
using std::swap;

class Solution_4 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtracking(nums, 0, res);
        return res;
    }

private:
    void backtracking(vector<int> &nums, int level, vector<vector<int>> &res) {
        if (level == nums.size() - 1) {
            res.push_back(nums);
            return;
        }

        for (int i = level; i < nums.size(); i++) {
            swap(nums[i], nums[level]);     // 修改当前节点的状态
            backtracking(nums, level + 1, res); // 递归子节点
            swap(nums[i], nums[level]);     // 恢复当前节点状态
        }
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394

