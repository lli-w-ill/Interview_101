#include <vector>
#include <iostream>

using std::vector;
using std::ostream;
using std::cout;

ostream& operator<< (ostream &out, vector<int> &vec) {
    out << '[' << ' ';
    for (const int &i : vec) {
        out << i << " ";
    }
    out << ']';
    return out;
}

class Solution_8 {
public:
    int lengthOfLIS(vector<int>& nums) {    
        int size = nums.size();
        int res = 0;    // 同时记录「dp 使用的最后一位下标的后一位」和「LIS 的长度」

        vector<int> dp (size, 0);

        for (int &num : nums) {
            // 二分法：找到大于等于 num 的最小值 dp[left]
            // 采用「左闭右开」原则
            int left = 0;
            int right = res;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (dp[mid] >= num) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            dp[left] = num;

            // 疑问：当输入数组是 [10,9,2,5,3,1,7,101,18] 时，1 会替换出现在它之前的 2，导致 [1,3,7] 是 LIS 的 “假象”
            // cout << dp << endl;

            // 如果 res == left，说明 num 是当前 dp 中的最大数字，则递增 res
            if (res == left) {
                res ++;
            }
        }
        
        return res;
    }

};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
// 参考题解：https://blog.csdn.net/qq_43152052/article/details/104090137
// lower_bound 参考：http://www.cplusplus.com/reference/algorithm/lower_bound/?kw=lower_bound
// 设 N = nums.size()
// time complexity: O(N * logN)
// space complexity: O(N)
