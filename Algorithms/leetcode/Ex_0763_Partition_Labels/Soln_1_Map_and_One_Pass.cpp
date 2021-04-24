#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::string;
using std::vector;
using std::unordered_map;
using std::max;

class Solution_1 {
public:
    vector<int> partitionLabels(string S) {
        // key: 字符 char
        // value: char 的信息
        unordered_map<char, Info> ump;

        // 预处理统计每个字符的信息
        int size = S.size();
        for (int i = 0; i < size; i++) {
            char ch = S[i];
            if (ump.count(ch)) {
                // cout << ch << " " << i << " " << ump.count(ch) << endl;
                // 更新 ch 的频率和最后一次出现下标
                ump[ch].freq = ump[ch].freq + 1;
                ump[ch].lastIdx = i;
            } else {
                Info info (1, i, i);
                ump.insert({ch, info});
            }
        }

        // 输出预处理统计的信息
        // for (const auto &[key, value] : ump) {
        //     cout << key << ": " << value.freq << " " << value.firstIdx << " " << value.lastIdx << endl;
        // }

        // 从前往后开始扫描 S，并同时记录当前字符串中所有字符最大的 lastIdx
        int maxLastIdx = -1;
        string curStr = "";     // 当前字符串（不必要）
        int curStrLen = 0;      // 当前字符串长度 
        vector<string> resStr;  // 记录所有分割字符串（不必要）
        vector<int> resLen;     // 记录所有分割字符串长度

        for (int i = 0; i < size; i++) {
            char ch = S[i];
            if (maxLastIdx == -1) {
                // 说明 ch 是新一个分割字符串的开始
                maxLastIdx = ump[ch].lastIdx;
            }
            if (i == maxLastIdx) {
                // 当前下标等于「当前字符串中所有字符中最大的 lastIdx」，在当前字符的后面分割
                // 将当前字符加到 curStr 后面，递增长度，之后加入到结果集中
                curStr += ch;
                curStrLen += 1;
                resStr.push_back(curStr);
                resLen.push_back(curStrLen);
                // 初始化 maxLastIdx, curStr, curStrLen
                maxLastIdx = -1;
                curStr = "";
                curStrLen = 0;
            } else if (i < maxLastIdx) {
                // 当前字符还不到要分割的位置
                // 更新当前字符串、当前字符串长度、当前字符串中所有字符中最大的 lastIdx
                curStr += ch;
                curStrLen += 1;
                maxLastIdx = max(maxLastIdx, ump[ch].lastIdx);
            } else if (i > maxLastIdx) {
                // 这种情况说明当前字符 ch 已经大于了「当前字符串中所有字符中最大的 lastIdx」
                // 除了 maxLastIdx = -1 的初始情况符合这种情况，根据贪心策略，这种情况不会发生，因为一旦到了 maxLastIdx 就会加到结果集中，并初始化 maxLastIdx
                continue;
            }
        }

        return resLen;
    }

private:
    struct Info {
        int freq;       // s 中出现的次数
        int firstIdx;   // s 中第一次出现的下标位置
        int lastIdx;    // s 中最后一次出现的下标位置

        // 构造函数
        // 必须要提供一个空的构造函数（不知道原因，否则会出错）
        Info () {

        }

        Info (int freq, int first, int last) : freq {freq}, firstIdx {first}, lastIdx {last} {
        }
    };
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394

