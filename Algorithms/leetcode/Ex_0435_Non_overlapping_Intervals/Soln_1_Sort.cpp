#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

class Solution_1 {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }

        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            if (a[1] <= b[1]) {
                // a 的结束区间比 b 的结束区间靠前，所以排序后 a 在 b 的前面
                return 1;
            } else {
                return 0;
            }
        });

        // 打印排序后的区间
        // for (const vector<int> &v : intervals) {
        //     cout << '[' << v[0] << ',' << v[1] << ']' << ", ";
        // }
        // cout << endl;

        int size = intervals.size();
        int endRange = intervals[0][1];     // 初始将第一个结束区间最靠前的结束点作为初始的结束区间
        int removeCnt = 0;
        for (int i = 1; i < size; i++) {
            if (intervals[i][0] < endRange) {
                // 当前区间的开始区间 小于当前的结束区间，重叠
                removeCnt ++;
            } else {
                // 如果不重合，则更新结束区间为当前区间的结束区间
                endRange = intervals[i][1];
            }
        }

        return removeCnt;
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
