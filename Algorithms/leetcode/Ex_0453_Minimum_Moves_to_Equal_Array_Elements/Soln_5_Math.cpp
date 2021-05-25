#include <vector>

using std::vector;

class Solution_5 {
public:
    int minMoves(vector<int>& nums) {
        int moves = 0;      // 记录当前已经移动了的步数
        int min = INT_MAX;  // 记录当前为止的最小值
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            moves += nums[i];
            min = std::min(min, nums[i]);
        }
        
        return moves - min * size;
    }
};

// 参考题解：https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements/solution/zui-xiao-yi-dong-ci-shu-shi-shu-zu-yuan-su-xiang-d/
// 
// 设 N = nums.size()
// time complexity: O(N)
// space complexity: O(1)
