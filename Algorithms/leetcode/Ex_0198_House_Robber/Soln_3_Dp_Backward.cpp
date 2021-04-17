#include <vector>
#include <algorithm>

using std::vector;
using std::max;

class Solution_3 {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) {
            return 0;
        }
        if (size == 1) {
            return nums[0];
        }
        if (size == 2) {
            return max(nums[0], nums[1]);
        }
        // 思路：开始投的房子下标从后往前移，每次考虑从当前的房子往后偷，最多能偷多少钱
        // memo[i] 表示 nums[i ... size-1] 能偷到最多的钱
        vector<int> memo (size, -1);
        // 初始化最后两位
        memo[size-1] = nums[size-1];    // nums[size-1 ... size-1] 最多只能偷到最后一个房子里的前
        memo[size-2] = max(nums[size-1], nums[size-2]); // 如果只能最后两栋房子，那么就偷钱多的那栋房子
        for (int i = size - 3; i >= 0; i--) {
            // memo[i+2] + nums[i] : 代表「偷房子 i 然后加上 nums[i+2 ... size-1] 能偷到最多的钱」 就是 「选择偷房子i时，能偷到nums[i ... size-1]最多的钱」
            // memo[i+1] : 代表「选择不偷房子i能偷到 nums[i ... size-1] 最多的钱」
            memo[i] = max(memo[i + 2] + nums[i], memo[i + 1]);
        }
        return memo[0];
    }
};
