#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

class Solution_2 {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // 对两个数组进行排序
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int gSize = g.size();
        int sSize = s.size();
        int child = 0;  // g 下标
        int cookie = 0; // s 下标
        while (child < gSize && cookie < sSize) {
            if (g[child] <= s[cookie]) {
                child ++;
            }
            cookie ++;  // s 的下标总是向前的，不管当前孩子吃得饱吃不饱
        }

        return child;   // 用最后在 g 中的下标来表示有多少孩子吃饱了
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394

