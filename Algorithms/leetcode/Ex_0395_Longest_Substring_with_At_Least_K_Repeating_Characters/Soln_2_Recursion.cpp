#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using std::max;
using std::string;
using std::vector;
using std::unordered_set;
using std::unordered_map;

class Solution_2 {
public:
    int longestSubstring(string s, int k) {
        // base case
        if (s.size() < k) {
            return 0;
        }

        // s 中出现过的字符
        unordered_set<char> chars (s.begin(), s.end());
        // key: s 中的字符
        // value: s 中该字符出现的次数
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c] ++;
        }

        for (char c : chars) {
            vector<string> substrings;   // 记录所有分割之后的子字符串
            if (freq[c] < k) {
                // 如果当前字符的出现频率就小于 k，那么以当前位置分割 s，将子字符串存在 t 中
                split(s, substrings, c);    // c 是 delimiter

                // 对分割后的每一个子串进行相同问题的搜索
                int res = 0;
                for (string substr : substrings) {
                    res = max(res, longestSubstring(substr, k));
                }

                // 这里直接返回即可，因为 res 相当于 s 上符合题意的最优结果
                // 对于子问题（即当前 s 其实是最开始 s 的一个子串，那么 res 也是子问题的最优结果，计算完返回给父问题
                return res;
            }
        }

        return s.size();
    }

private:
    void split(const string &s, vector<string> &substrings, const char delimiter = ' ') {
        substrings.clear();
        size_t pos = 0;
        string str = s;
        while ((pos = str.find(delimiter)) != string::npos) {
            string sub = str.substr(0, pos);
            substrings.push_back(sub);

            // 从 str 中移除 sub 部分 + 1 位 delimiter
            str.erase(0, pos + 1);  // 1 是 delimiter 的长度
        }

        // 将 s 中最后一个由 delimiter 分割的子串加入到 substrings
        // 因为如果 deliminter 不是 s 中的最后一个字符，最后一个子串还没有加入到 substrings
        if (str.size() != 0) {
            substrings.push_back(str);
        }
    }
};

// 参考题解（非常推荐）：https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters/solution/jie-ben-ti-bang-zhu-da-jia-li-jie-di-gui-obla/
// C++ 根据 delimiter 分割字符串：https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
