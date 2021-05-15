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

class Solution_9 {
public:
    int lengthOfLIS(vector<int>& nums) {    
        int size = nums.size();

        vector<int> dp;

        for (int &num : nums) {
            // 二分法：找到大于等于 num 的最小值 dp[left] 的下标
            auto idx = lower_bound(dp.begin(), dp.end(), num) - dp.begin();
            
            if (idx >= dp.size()) {
                // num 比 dp 中所有数字都大，插在 dp 的最后面
                dp.emplace_back(num);
            } else {
                dp[idx] = num;
            }

            // 当输入数组是 [10,9,2,5,3,1,7,101,18] 时，输出为：
            // [ 10 ]
            // [ 9 ]
            // [ 2 ]
            // [ 2 5 ]
            // [ 2 3 ]
            // [ 1 3 ]          // ??? 1 出现在 3 的后面啊
            // [ 1 3 7 ]        // ???
            // [ 1 3 7 101 ]    // ???
            // [ 1 3 7 18 ]     // ???
            // cout << dp << endl;
        }
        
        return dp.size();
    }

};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
// 参考题解：https://blog.csdn.net/qq_43152052/article/details/104090137
// lower_bound 参考：http://www.cplusplus.com/reference/algorithm/lower_bound/?kw=lower_bound
// 设 N = nums.size()
// time complexity: O(N * logN)
// space complexity: O(N)
