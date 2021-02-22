#include <vector>
#include <algorithm>

using std::vector;
using std::max;

class Tle_1 {
public:
    int rob(vector<int>& nums) {
        // 思路：小偷对与每个房屋只有偷／不偷的选择，所以整体下来应该可以理解成是对一个树的遍历，但是这遍历是有条件的，即如果小偷偷了父节点，就不能再偷当前节点，且在遍历当前节点的孩子时需要再次激活「偷的技能」
        rob(nums, 0, true, 0);
        return res;    
    }

private:
    int res = 0;

    int rob(vector<int> &nums, int curIdx, bool canRob, int money) {
        if (curIdx == nums.size()) {
            return money;
        }
        if (canRob) {
            // 偷 curIdx 能偷到的最多钱
            int robCur = rob(nums, curIdx + 1, false, money + nums[curIdx]);
            // 不偷 curIdx 能偷到的最多钱
            int notRobCur = rob(nums, curIdx + 1, true, money);
            res = max(res, max(robCur, notRobCur));
            return max(robCur, notRobCur);
        } else {
            // 因为父节点被偷了，所以不能偷当前的，激活「偷的技能」，直接访问下一个节点
            return rob(nums, curIdx + 1, true, money);
        }
    }
};
