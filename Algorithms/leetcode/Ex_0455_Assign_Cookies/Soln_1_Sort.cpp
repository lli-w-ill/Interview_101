#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

class Solution_1 {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // 对两个数组进行排序
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int gSize = g.size();
        int sSize = s.size();
        int res = 0;    // 记录有多少孩子能饱
        for (int i = 0, j = 0; i < gSize && j < sSize; ) {
            if (g[i] <= s[j]) {
                // 累加结果
                res ++;
                // 数组 g 的下标 i 和数组 s 的下标 j 同时并进
                i ++;
                j ++;
            } else {
                // 当前饼干 s[j] 不能喂饱孩子 i，考虑更大的饼干，保持孩子不变
                j ++;
            }
        }

        return res;
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394

