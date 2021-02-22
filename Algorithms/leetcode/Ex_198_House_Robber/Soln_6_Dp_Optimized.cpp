#include <vector>
#include <algorithm>

using std::vector;
using std::max;

class Solution_6 {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) {
            return 0;
        }
        // vector<int> memo (size, -1);
        
        // 前 0 栋楼能偷到最多 0 元 (i = 0)
        // memo[0] = 0;
        int firstIMinusOneMax = 0;
        
        // 前 1 栋楼最多只能偷 nums[0] 元 (i = 1)
        // memo[1] = nums[0];
        int firstIMax = nums[0];
        
        for (int i = 1; i < size; i++) {    // 因为下标是从 0 开始的，所以 i=1 时要更新的是「前 i+1 栋楼能偷的最多的钱」
            // memo[i] 表示不偷第 i+1 栋楼，所以前 i+1 栋楼最多偷的钱 = 前 i 栋楼最多偷的钱
            // memo[i-1] + nums[i] 表示偷第 i+1 栋楼，所以前 i+1 栋楼最多偷的前 = 在第 i+1 栋楼偷的前 + 前 i-1 栋楼最多能偷的钱
            // memo[i + 1] = max(memo[i], memo[i - 1] + nums[i]);
            
            // 先备份上一轮循环 i 时（即i-1），前 i-1 + 1 栋楼能偷最多的钱（这里不能直接更新 firstIMinusOneMax，因为下一行计算新的 firstIMax 时需要用到旧的 firstIMinusOneMax）
            int temp = firstIMax;
            // 更新这一轮 i，前 i+1 栋楼能偷到的钱
            //              firstImax: 表示不偷第 i+1 栋楼，所以前 i+1 栋楼能偷到的钱 = 前 i 栋楼能偷到的钱
            //                         firstIMinusOneMax + nums[i]: 表示偷第 i+1 栋楼，所以前 i+1 栋楼能偷到的钱 = 前 i-1 栋楼能偷到的钱 + 在第 i+1 栋楼偷到的钱
            firstIMax = max(firstIMax, firstIMinusOneMax + nums[i]);
            // 更新前 i-1 栋楼能偷到的钱（就是上一轮循环 i 时（即这一轮循环的 i-1）最多能偷到的钱）
            firstIMinusOneMax = temp;
        }
        // 返回前 size 栋楼最多能偷的钱
        // return memo[size];
        // 最后 i = size，返回前 size 栋楼最多偷的钱
        return firstIMax;
    }
};
