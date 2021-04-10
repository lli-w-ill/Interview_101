#include <string>
#include <vector>

using std::string;
using std::vector;

class Tle_1 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // base case
        if (s.size() == 0) {
            return true;
        }
        for (int i = 0; i < wordDict.size(); i++) {
            if (s.size() < wordDict[i].size()) {
                continue;
            }
            // 在s中从下标0开始取和当前wordDict正在匹配的单词相同长度的子串
            string sub = s.substr(0, wordDict[i].size());
            // 与当前wordDict正在匹配的单词进行匹配
            if (sub == wordDict[i]) {
                if (wordBreak(s.substr(sub.size()), wordDict)) {
                    // 如果匹配，截掉匹配单词的长度，剩下部分继续与wordDict匹配，直到s为空为止
                    // 如果不匹配，尝试与wordDict下一个单词进行匹配
                    return true;
                }
            }
        }
        return false;
    }
};

// 注：就这道题，recursion 解法其实相当于 brute force 解法
// 超时测试用例：
// "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
// ["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
