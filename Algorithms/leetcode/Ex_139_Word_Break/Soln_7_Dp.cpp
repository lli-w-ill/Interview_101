#include <string>
#include <vector>
#include <set>
#include <algorithm>

using std::string;
using std::vector;
using std::set;
using std::fill;

class Solution_7 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> wordSet;
        const int lenS = s.size();
        // 将 wordDict 中的单词依次加入到 set 中
        for (int i = 0; i < wordDict.size(); i++) {
            wordSet.insert(wordDict[i]);
        }
        // 初始化 dp 数组
        bool dp[lenS + 1];
        fill(dp, dp + lenS + 1, false);
        dp[0] = true;
        // 开始 dp
        for (int i = 1; i <= lenS; i++) {   // i: s子串的结束位置（不包含i），即到s[0 ...i-1] 或 s[0 ... i)
            for (int j = i - 1; j >= 0; j--) {  // j: 在 0 ... i 中切分子串s [0 ... i)
                // 查看 s[j...i) 是否在 wordSet 中是一个单词
                string sub = s.substr(j, i - j);
                // dp[i] 取决于 2. 剩余子串 s[j ... i) 是否是 wordSet 中的一个单词
                if (wordSet.find(sub) != wordSet.end()) {
                    // ok, s[j ... i) 是一个单词，接下来
                    // dp[i] 取决于 1. dp[j] 是否为true，即 s[0 ... j) 是否可以拆分
                    if (dp[j] == true) {
                        dp[i] = true;   // s[0 ... i) 可以划分
                        break;  // s[0 ... i) 可以划分，不需要 j 继续切分了
                    }                    
                }
            }
        }
        return dp[lenS];
    }
};

// 题解参考（强烈推荐）：https://leetcode-cn.com/problems/word-break/solution/shou-hui-tu-jie-san-chong-fang-fa-dfs-bfs-dong-tai/
// DP解题思路（强烈推荐）：https://leetcode-cn.com/problems/longest-palindromic-substring/solution/zhong-xin-kuo-san-dong-tai-gui-hua-by-liweiwei1419/
// 状态：前 i 个字符是否可以拆分成 wordDict 中的单词组合，问题问的是：相当于 i = s.size()
// dp[i+1] 如果为 true，那么表示 s[0 ... i] 可以拆分
//         如果为 false，那么则不可以拆分
//
// 状态转移方程：（配合题解参考中的插图）
// dp[i] 是否为 true，即 s[0 ... i) 是否可以拆分取决于:
//      1. dp[j] 是否为true，即 s[0 ... j) 是否可以拆分
//      2. 剩余子串 s[j ... i) 是否是 wordSet 中的一个单词
// j 用作取划分 s[0 ... i)，所以 0 <= j <= i-1
//
// 初始化：dp[0] = true，长度为0的子串 s[0 ... -1] 能拆分为单词，因为是空串
