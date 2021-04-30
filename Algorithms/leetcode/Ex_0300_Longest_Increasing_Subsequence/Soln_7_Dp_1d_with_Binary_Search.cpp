#include <vector>
#include <algorithm>    // std::lower_bound
#include <iostream>

using std::vector;
using std::lower_bound;
using std::cout;
using std::ostream;

ostream& operator<< (ostream &out, vector<int> &vec) {
    out << '[' << ' ';
    for (const int &i : vec) {
        out << i << " ";
    }
    out << ']';
    return out;
}

class Solution_7 {
public:
    int lengthOfLIS(vector<int>& nums) {    
        int size = nums.size();
        
        // dp 永远存放「对未来更有可能构成更长的递增序列」的递增子序列
        // dp[i] 表示长度为 i+1 的 LIS 的最后一个数字
        vector<int> dp {nums[0]};

        // 打印最开始的 dp 数组
        // cout << dp << endl;

        for (int i = 1; i < size; i++) {
            if (dp.back() < nums[i]) {
                // 如果当前数字大于目前最长子序列的最后（也是最大）一个数字
                // 则将当前数字加入到最长子序列中
                dp.push_back(nums[i]);
            } else {
                // 如果当前数字小于等于目前最长子序列的最后一个数字
                // 那么为了最大化「当扫描到未来的数字时可以构成更长的递增序列」，需要找到目前最长子序列 (dp) 中将将大于 nums[i] 的下标，并将其位置的数字替换成 nums[i] 
                auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
                // 这里有个疑问：为什么是『替换』而不是『后移』呢？
                // 回答：那是因为 「将将大于 nums[i] 的数字是出现在 nums[i] 之前的」
                *it = nums[i];
            }
            // 查看每一轮 dp 中的数字（本轮的「最为未来考虑的最长递增子序列」）
            // cout << dp << endl;
        }

        return dp.size();
    }

    
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
// lower_bound 参考：http://www.cplusplus.com/reference/algorithm/lower_bound/?kw=lower_bound
// 设 N = nums.size()
// time complexity: O(NlogN)
// space complexity: O(N)
