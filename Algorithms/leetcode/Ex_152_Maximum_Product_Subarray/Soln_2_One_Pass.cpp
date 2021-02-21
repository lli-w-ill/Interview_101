#include <vector>
#include <algorithm>    // std::min, std::max

using std::vector;
using std::min;
using std::max;

class Solution_2 {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        }
        int preMinProduct = nums[0]; // 记录到当前下标 i 为止（不包括当前 i），nums[0 ... i) 中最小的连续乘积
        int preMaxProduct = nums[0]; // 记录到当前下标 i 为止（不包括当前 i），nums[0 ... i) 中最大的连续乘积
        int res = nums[0];
        for (int i = 1; i < len; i++) {
            // nums[0 ... i] 的最大乘积可能有 3 个来源：
            //  1. nums[i] * preMaxProduct 的乘积会更大
            //  2. nums[i] 最大 或者 当nums[i]=0时将累计最大乘积拉至0
            //  3. nums[i] * preMinProduct 的乘积会负负得正
            int curMaxProduct = max(preMaxProduct * nums[i], max(nums[i], preMinProduct * nums[i]));
            // 同理，nums[0 ... i] 的最小乘积可能有 3 个来源：
            //  1. nums[i] * preMinProduct 的乘积会更小
            //  2. nums[i] 最小 或者 当nums[i]=0时将累计最小乘积拉至0
            //  3. nums[i] * preMaxProduct 的乘积正负得负
            int curMinProduct = min(preMinProduct * nums[i], min(nums[i], preMaxProduct * nums[i]));

            // 更新累计最大乘积
            if (curMaxProduct > res) {
                res = curMaxProduct;
            }
            
            // 更新累计最大／最小乘积
            preMaxProduct = curMaxProduct;
            preMinProduct = curMinProduct;
        }
        return res;
    }
};
