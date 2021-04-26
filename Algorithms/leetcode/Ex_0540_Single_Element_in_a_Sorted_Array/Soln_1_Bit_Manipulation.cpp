#include <vector>

using std::vector;

class Solution_1 {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res = 0;
        for (const int &num : nums) {
            res ^= num;
        }
        return res;
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394

