#include <vector>
#include <string>
#include <map>
#include <algorithm>

using std::vector;
using std::string;
using std::map;
using std::sort;

class Solution_1 {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        // 先通过长度有长到短，如果长度相同则按照字典顺序，排序dictionary
        sort(dictionary.begin(), dictionary.end(), [](const string &s1, const string &s2) -> int {
            if (s1.size() > s2.size()) {
                // 排序后 s1 排在 s2 前面
                return 1;
            } else if (s1.size() < s2.size()) {
                // 排序后 s1 排在 s2 后面
                return 0;
            } else if (s1.size() == s2.size()) {
                // 按照字典顺序，谁更小谁排前
                // e.g. ["abc", "abd"]
                for (int i = 0; i < s1.size(); i++) {
                    if (s1[i] < s2[i]) {
                        return 1;
                    } else if (s1[i] > s2[i]) {
                        return 0;
                    }
                }
                // 说明 s1 == s2
                return 0;
            }
            return 0;
        });

        // 输出排序后结果
        // for (const string &s : dictionary) {
        //     cout << s << " ";
        // }

        // 记录 s 中每个字符第一次出现的下标
        map<char, int> firstAppear;
        for (int i = 0; i < s.size(); i++) {
            if (!firstAppear.count(s[i])) {
                // 第一次出现
                firstAppear.insert({s[i], i});
            }
        }

        // 从 dictionary 中最长且字典顺序最小的字符串开始检查
        for (int i = 0; i < dictionary.size(); i++) {
            string dictWord = dictionary[i];
            int dwIdx = 0;  // dictWord[dwIdx] 表示当前要在 s 中找的匹配的字符

            // 先检查第一个字符是否在 s 中
            if (!firstAppear.count(dictWord[dwIdx])) {
                continue;
            }

            // 从 s 中第一次出现 dictWord[0] 字符的下标开始往后扫描
            // for 条件：当前还未达到 dictWord 尾部
            for (int sIdx = firstAppear[dictWord[dwIdx]]; sIdx < s.size() && dwIdx < dictWord.size(); sIdx++) {
                if (s[sIdx] == dictWord[dwIdx]) {
                    // s 中当前字符与 dictWord 当前字符相同，则检查 dictWord 下一个字符
                    dwIdx ++;
                    // 检查下一个字符是否在 s 中存在
                    if (!firstAppear.count(dictWord[dwIdx])) {
                        // 如果不存在就没必要继续往后找了，直接换 dictionary 中下一个 string
                        break;
                    }
                }
            }
            // cout << dictWord << " " << dwIdx << endl;
            if (dwIdx == dictWord.size()) {
                // 找到了当前的第一个最优解，直接返回即可
                return dictWord;
            }
        }

        // 没有解，返回空字符
        return "";
    }
};


// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
