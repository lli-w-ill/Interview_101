#include <vector>

using std::vector;

class Solution_1 {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> combo (k, 0);
        int count = 0;  // 记录 combo 中已经填入的数字数，同时作为在 combo 中当前需要填入数字的下标
        backtracking(res, combo, count, 1, n, k);
        return res;
    }

private:
    void backtracking(vector<vector<int>> &res, vector<int> &combo, int &count, int pos, int n, int k) {
        if (count == k) {
            // 当前已经从 1~n 数字中选了 k 个数字填入了 combo
            res.push_back(combo);
            return;
        }

        for (int i = pos; i <= n; i++) {
            combo[count] = i;
            count ++;   // 修改当前节点状态
            backtracking(res, combo, count, i + 1, n, k);   // 递归子节点
            -- count;   // 恢复当前节点状态
        }
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
