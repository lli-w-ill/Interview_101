#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution_9 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.size();

        // dp[i] 表示 s[0 ... i-1] 是否可以由 wordDict 中的单词分割
        vector<bool> dp (size + 1, false);

        // base case: s[0, -1] 为空，所以可以由 wordDict 中的单词分割
        dp[0] = true;

        for (int i = 1; i <= size; i++) {
            // 遍历 wordDict，确定当前 s[0 ... i-1] 是否可以分割
            for (const string &word : wordDict) {
                int wordLen = word.size();
                if (i >= wordLen && s.substr(i - wordLen, wordLen) == word) {
                    dp[i] = dp[i] || dp[i - wordLen];
                }
            }
        }

        return dp[size];
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394

