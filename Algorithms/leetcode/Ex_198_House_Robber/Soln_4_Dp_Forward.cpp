#include <vector>
#include <algorithm>

using std::vector;
using std::max;

class Solution_4 {
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
        // memo[i] 表示 nums[0 ... i] 能偷到最多的钱
        vector<int> memo (size, -1);
        // 初始化前面两位
        memo[0] = nums[0];    // nums[0 ... 0] 最多只能偷到第一个房子里的前
        memo[1] = max(nums[0], nums[1]); // 如果只能偷前两栋房子，那么就偷钱多的那栋房子
        for (int i = 2; i < size; i++) {
            // memo[i-2] + nums[i] : 代表「偷房子 i 然后加上 nums[0 ... i-2] 能偷到最多的钱」 就是 「选择偷房子i时，能偷到nums[0 ... i]最多的钱」
            // memo[i-1] : 代表「选择不偷房子i能偷到 nums[0 ... i] 最多的钱」
            memo[i] = max(memo[i - 2] + nums[i], memo[i - 1]);
        }
        return memo[size-1];
    }
};
