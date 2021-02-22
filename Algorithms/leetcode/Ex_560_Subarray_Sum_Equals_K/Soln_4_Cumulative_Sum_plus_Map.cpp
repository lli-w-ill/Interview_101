#include <vector>
#include <utility>  // std::pair
#include <map>

using std::vector;
using std::pair;
using std::map;

class Solution_4 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        int len = nums.size();
        // 思路：
        // 如果      sum( nums[0 ... i] ) == sum( nums[0 ... j] ) 且 i < j
        // 则可以推出 sum( nums[i+1 ... j] ) == 0
        // 进而可以假设如果 sum( nums[0 ...i] ) + k = sum( nums[0 ... j] ) 且 i < j
        // 那么说明        k == sum( nums[i+1 ... j] )
        //
        // 用一个map存储
        // key: sum up to index i (include i) 即 sum( nums[0 ... i] ), called sum_i
        // value: no. of occurrences of sum_i so far
        map<int, int> cumulativeSum;
        cumulativeSum.insert(pair<int, int> (0, 1));    // base case，因为sum( nums[0 ... -1] ) = 0，因为这一段子串为空
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum += nums[i];
            if (cumulativeSum.find(sum - k) != cumulativeSum.end()) {
                // 即 sum( nums[0 ... ?] ) == sum-k 存在（注意这里 ? 可能是不止一个下标，也就是说 sum( nums[0 ... 1] )可能等于sum-k，sum( nums[0 ... 5] ) 可能也等于 sum-k）
                // 那么由于累加和到当前下标 i 为 sum，即 sum( nums[0 ... i] ) == sum
                // 所以 sum( nums[?+1 ... i] ) == sum - (sum-k) = k
                // 直接将结果加上之前累加和 sum-k 出现的次数即可
                res += cumulativeSum[sum-k];
            }
            // 将 到当前下标i的累加和对应的 occurrence 加一，如果累加和未曾出现则新加入一项，并将出现次数设为1
            if (cumulativeSum.find(sum) != cumulativeSum.end()) {
                cumulativeSum[sum] += 1;
            } else {
                cumulativeSum.insert(pair<int, int> (sum, 1));
            }
        }
        return res;
    }
};

// 参考题解（推荐）：https://leetcode.com/problems/subarray-sum-equals-k/solution/
// 建议配合题解一起看（推荐）：https://leetcode-cn.com/problems/subarray-sum-equals-k/solution/bao-li-jie-fa-qian-zhui-he-qian-zhui-he-you-hua-ja/
