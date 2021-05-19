#include <vector>
#include <iostream>

using std::vector;
using std::ostream;
using std::cout;
using std::endl;
using std::max;

ostream& operator<< (ostream& os, vector<int> &v) {
    for (int &num : v) {
        os << num << " ";
    }
    return os;
}

class Solution_1 {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int size = nums.size();

        // dp[i] 表示以 nums[i] 结尾的最长递增子序列的长度
        vector<int> dp (size, 1);

        // cnt[i] 表示以 nums[i] 结尾的所能构成最长递增子序列长度 (即 dp[i]) 的个数
        // 例子：输入数组为 [1, 2, 4, 3, 5, 4, 7, 2]
        //      那么 cnt[4] = 2，因为以 nums[4] 结尾所能构成长度为 dp[4]=4 的最长递增子序列长度有两个, [1, 2, 4, 5] 和 [1, 2, 3, 5]
        vector<int> cnt (size, 0);
        // base case: 以 nums[0] 结尾最长的递增子序列只能是 nums[0] 自身
        // cnt[0] = 1;
        
        int longest_subsequence_len = 0;
        int res = 0;    // 记录答案

        // 开始填数组
        for (int i = 0; i < size; i++) {
            int num = nums[i];
            int longest_seq_len = 1;        // 记录以 nums[i] 结尾的最长递增子序列的长度
            int longest_seq_num = 1;        // 记录以 nums[i] 结尾的最长递增子序列的个数
            
            for (int j = 0; j < i; j++) {
                if (nums[j] < num) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    
                    if (dp[j] + 1 > longest_seq_len) {
                        longest_seq_len = dp[j] + 1;        // 更新长度
                        longest_seq_num = cnt[j];           // 重新开始累计
                    } else if (dp[j] + 1 == longest_seq_len) {
                        longest_seq_num += cnt[j];
                    }
                }
            }

            // 更新 longest_subsequence_len, res
            if (longest_subsequence_len < longest_seq_len) {
                // 找到了新的更长的最长递增子序列
                // 更新长度
                longest_subsequence_len = longest_seq_len;
                // 更新个数
                res = longest_seq_num;
            } else if (longest_subsequence_len == longest_seq_len) {
                // 找到了相同长度的最长递增子序列
                // 只更新个数
                res += longest_seq_num;
            }

            cnt[i] = longest_seq_num;
        }

        cout << "cnt: " << cnt << endl;
        cout << "dp: " << dp << endl;

        return res;

    }
};

// 相关题目：Ex.300, Ex.354
