#include <vector>
#include <algorithm>

using std::vector;
using std::max;

class Solution_5 {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) {
            return 0;
        }
        // memo[i] 表示前 i 栋楼能偷到的最多的钱是多少
        vector<int> memo (size + 1);
        // 前 0 栋楼能偷到最多 0 元
        memo[0] = 0;
        // 前 1 栋楼最多只能偷 nums[0] 元
        memo[1] = nums[0];
        for (int i = 1; i < size; i++) {    // 因为下标是从 0 开始的，所以 i=1 时要更新的是「前 i+1 栋楼」能偷的最多的钱
            // memo[i] 表示不偷第 i+1 栋楼，所以前 i+1 栋楼最多偷的钱 = 前 i 栋楼最多偷的钱
            // memo[i-1] + nums[i] 表示偷第 i+1 栋楼，所以前 i+1 栋楼最多偷的前 = 在第 i+1 栋楼偷的前 + 前 i-1 栋楼最多能偷的钱
            memo[i + 1] = max(memo[i], memo[i - 1] + nums[i]);
        }
        // 返回前 size 栋楼最多能偷的钱
        return memo[size];
    }
};

// 时间复杂度：O(n)
// 空间复杂度：O(n)
// 其实我们在计算 memo[i+1] 是真正需要也只有 memo[i] 和 memo[i-1]
// 所以可以继续优化空间复杂度，见 Soln_6
