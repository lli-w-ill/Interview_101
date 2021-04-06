#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution_2 {
public:
    int numDecodings(string s) {
        // dp[i] 表示 s[0 ... i-1] 解码方法总数
        vector<int> dp(s.size() + 1, 0);
        
        dp[0] = 1;  // dummy 位（至于为什么置为1而不是0，见参考题解下方评论 @图书管理员 下方 @Victor Martinez 的解释：「代码里的dp[0]，实际上表示的是公式里的dp[-1]。-1这个肯定没有含义，但是注意到情况二和情况三，在一开始i=1，没有dp[i-2]这个值，而此时又必须给现有的编码数量加一（因为在这两种情况下多了一种编码方案），所以最好的办法就是初始化一个dp[-1] 或者 pre 等于1。这种做法保证了代码的统一和简洁。」）

        // 检查第一位 (base case)
        if (s[0] >= '1' && s[0] <= '9')
            dp[1] = 1;
        else {
            // "0" 无法单独解码
            dp[1] = 0;
            // 因为如果第一位都无法解码，那么后面一定也无法解码，所以直接返回即可
            return 0;
        }
            
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '0') {
                if (s[i-1] == '1' || s[i-1] == '2')
                    // 这里因为 s[i] 已经是 0 了，所以不用检查 0 <= s[i] <= 6
                    dp[i+1] = dp[i-1];
                else {
                    // 例子："2130213" 当检查到第 4 位时，发现是没有解法的，直接返回 0 即可，不用继续向后检查了
                    dp[i+1] = 0;
                    return 0;
                }
            } else {
                // 如果当前位 s[i] 可以与其前面一位一同被解码
                if (s[i-1] == '1' || (s[i-1] == '2' && s[i] >= '0' && s[i] <= '6'))
                    // dp[i]: 表示 s[i] 和 s[i-1] 分开解码
                    // dp[i-1]: 表示 s[i] 和 s[i-1] 合并解码
                    // 举例： s = "1 2 6 3"
                    // 当 i=2 时
                    // dp:      1 1 2 _ _
                    //   dp[i]: 表示"6"与"2"分开解码的方法总量 ———— 两种：("12", "6"), ("1", "2", "6")
                    //   dp[i-1]: 表示"6"与"2"合并解码的方法总量 ———— 一种：("1", "26")        
                    dp[i+1] = dp[i] + dp[i-1];

                // 如果不能被一同解码，那只能分开解码
                else
                    dp[i+1] = dp[i];
            }
        }

        // for (vector<int>::iterator it = dp.begin(); it != dp.end(); it++) {
        //     cout << *it << " ";
        // }
        // cout << endl;

        return dp[s.size()];
    }
};

// 参考题解：https://leetcode-cn.com/problems/decode-ways/solution/c-wo-ren-wei-hen-jian-dan-zhi-guan-de-jie-fa-by-pr/
