#include <vector>
#include <unordered_map>
#include <map>

using std::vector;
using std::unordered_map;
using std::map;
using std::max;

class Solution_4 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // key: nums 中的数字 num
        // value: num 在 nums 中出现的次数
        unordered_map<int, int> counts;
        // 计算 nums 中最频繁的数字所出现的次数，为了决定需要使用多少桶
        int max_count = 0;
        for (const int &num : nums) {
            counts[num] ++;
            max_count = max(max_count, counts[num]);
        }

        // 将每个数字放入「它所出现频率所对应的桶」
        // key: 出现的频率
        // value: 出现key频率的所有数字
        map<int, vector<int>> buckets;
        for (int i = 0; i < max_count; i++) {
            // 初始化每个桶
            buckets[i] = vector<int> {};
        }
        for (const auto &[key, value] : counts) {
            // key = num
            // value = frequency
            buckets[value].push_back(key);
        }

        // 从频率最大的桶开始，收集结果
        vector<int> res;
        for (int i = max_count; i >= 0 && res.size() < k; i--) {
            for (const int &num : buckets[i]) {
                res.push_back(num);
                // 如果对频率为 i 的桶处理过程中，结果集已经收集了 k 个数字，则直接返回即可
                if (res.size() == k) {
                    break;
                }
            }
        }

        return res;
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
