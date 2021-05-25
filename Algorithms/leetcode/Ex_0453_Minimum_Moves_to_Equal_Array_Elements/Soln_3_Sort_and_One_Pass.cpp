#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

class Solution_3 {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int size = nums.size();
        for (int i = size - 1; i >= 0; i--) {
            int diff = nums[i] - nums[0];
            res += diff;
        }
        return res;
    }
};

// 参考题解：https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements/solution/zui-xiao-yi-dong-ci-shu-shi-shu-zu-yuan-su-xiang-d/
// 
// 设 N = nums.size()
// time complexity: O(N * logN)
// space complexity: O(1)
