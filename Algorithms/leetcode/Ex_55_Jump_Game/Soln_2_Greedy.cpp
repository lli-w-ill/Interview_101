#include <vector>
#include <algorithm>

using std::vector;
using std::max;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int furthest = 0;   // 代表「能跳到最远的距离」
        for (int i = 0; i < nums.size(); i++) {
            if (i > furthest) {
                // 意味着i之前所有格子能跳到最远的距离都到不了当前下标位置i，所以更不可能跳到最后一个位置
                return false;
            }
            furthest = max(i + nums[i], furthest);
        }
        // 这里直接返回true即可，不需要再判断furthest >= num.size() - 1，因为i的最后一次循环值是nums.size() - 1，如果前面的不等式不满足，在最后一次循环就返回false
        return true;
    }
};

// 参考（推荐）：https://leetcode-cn.com/problems/jump-game/solution/55-by-ikaruga/
// 相对于Soln_1，这个解法是以从前往后的视角来解
