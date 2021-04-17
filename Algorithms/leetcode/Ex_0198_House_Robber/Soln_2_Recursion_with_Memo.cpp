#include <vector>
#include <algorithm>

using std::vector;
using std::max;

class Solution_2 {
public:
    int rob(vector<int>& nums) {
        // 思路：小偷对与每个房屋只有偷／不偷的选择，所以整体下来应该可以理解成是对一个树的遍历，但是这遍历是有条件的，即如果小偷偷了父节点，就不能再偷当前节点，且在遍历当前节点的孩子时需要再次激活「偷的技能」
        int size = nums.size();
        // 初始化备忘录
        memo = vector<int> (size, -1);
        return rob(nums, size - 1);    
    }

private:
    // int res = 0;
    // 用一个备忘录记录之后房屋能偷的最多钱数
    // 保存 nums[index ... size-1] 能偷的最多钱数
    vector<int> memo;

    int rob(vector<int> &nums, int curIdx) {
        if (curIdx < 0) {
            return 0;
        }
        if (memo[curIdx] >= 0) {
            return memo[curIdx];
        }
        // 偷／不偷，更新memo[curIdx]（nums[curIdx ... size-1] 能偷到的最多的钱）
        memo[curIdx] = max(rob(nums, curIdx - 2) + nums[curIdx], rob(nums, curIdx - 1));
        return memo[curIdx];
    }
};
