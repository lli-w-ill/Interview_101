#include <vector>

using std::vector;

class Solution_1 {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int> > res;
        res.push_back(vector<int>());
        if (len == 0) {
            return res;
        }
        for (int length = 1; length <= len; length++) {
            vector<int> temp;
            backtrack(nums, temp, 0, 0, length, res);
        }
        return res;
    }

private:
    void backtrack(vector<int> &nums, vector<int> &cur, int startIdx, int curLen, int tarLen,vector<vector<int> > &res) {
        if (curLen == tarLen) {
            // for (vector<int>::const_iterator i = cur.begin(); i != cur.end(); i++)
            //     cout << *i << ' ';
            // cout << endl;
            res.push_back(vector<int> (cur));   // 这里需要拷贝，因为cur传的是引用
            return;
        }
        for (int i = startIdx; i < nums.size(); i++) {
            cur.push_back(nums[i]);
            backtrack(nums, cur, i + 1, curLen + 1, tarLen, res);
            cur.pop_back(); // 恢复状态（回溯）
        }
    }
};
