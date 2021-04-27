#include <vector>
#include <string>
#include <unordered_map>

using std::vector;
using std::string;
using std::unordered_map;
using std::max;

class Solution_2 {
public:
    string frequencySort(string s) {
        if (s.empty()) {
            return "";
        }
        return bucketSort(s);
    }

private:
    string bucketSort(string s) {
        // 对 s 中每个字符进行排序
        unordered_map<char, int> freq;
        int max_freq = 0;
        for (char c : s) {
            freq[c] ++;
            max_freq = max(max_freq, freq[c]);
        }

        // 定义桶，并将所有字符装入对应出现频率的桶
        unordered_map<int, vector<int>> buckets;
        for (int i = 1; i <= max_freq; i++) {
            buckets[i] = vector<int> {};
        }
        for (const auto &[key, value] : freq) {
            buckets[value].push_back(key);
        }

        // 收集结果
        string res = "";
        for (int i = max_freq; i >= 1; i--) {
            if (buckets[i].size() > 0) {
                for (char c : buckets[i]) {
                    for (int j = 0; j < i; j++) {
                        res += c;
                    }
                }
            }
        }

        return res;
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
