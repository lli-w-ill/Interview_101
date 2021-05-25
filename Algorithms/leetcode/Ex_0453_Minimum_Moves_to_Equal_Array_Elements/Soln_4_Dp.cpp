#include <vector>

using std::vector;

class Solution_4 {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int moves = 0;      // 记录当前已经移动了的步数
        int size = nums.size();
        for (int i = 1; i < size; i++) {
            // moves + nums[i] 的原因是因为：在让 nums[0] 追上 nums[1], 让 nums[1] 追让 nums[2], ..., 让 nums[i-2] 追上 nums[i-1] 的过程中，
            // 我们一直没有递增 nums[0], nums[1], ..., nums[i-2] 之后下标的数字
            // 所以在当前 loop 循环考虑让 nums[i-1] 追上 nums[i] 时要递增的步数之前，需要将 nums[i] 加到它本应该递增到的数字，再减去 nums[i-1] 获得需要追上 nums[i] 所需递增的步数
            int diff = (moves + nums[i]) - nums[i - 1];
            
            // 更新当前下标的数字
            nums[i] += moves;

            // 更新为了让 nums[i-1] 追上 nums[i] 所需移动的步数
            moves += diff;
        }
        
        return moves;
    }
};

// 参考题解：https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements/solution/zui-xiao-yi-dong-ci-shu-shi-shu-zu-yuan-su-xiang-d/
// 
// 设 N = nums.size()
// time complexity: O(N * logN)
// space complexity: O(1)


// 参考题解：https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements/solution/zui-xiao-yi-dong-ci-shu-shi-shu-zu-yuan-su-xiang-d/
// 建议配合题解中的动画和这里的注释来理解
// 
// 设 N = nums.size()
// time complexity: O(N * logN)
// space complexity: O(1)
