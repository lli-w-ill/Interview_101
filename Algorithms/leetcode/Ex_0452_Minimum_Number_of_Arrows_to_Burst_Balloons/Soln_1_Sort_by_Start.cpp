#include <algorithm>
#include <vector>

using std::sort;
using std::max;
using std::min;
using std::vector;

class Solution_1 {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int size = points.size();
        if (size <= 1) {
            return size;
        }

        // 按照 start 给 pointer 中所有区间进行排序
        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b) -> int {
            if (a[0] < b[0]) {
                // 区间 a 比 区间 b 先开始，所以排序后 a 在 b 前
                return 1;
            } else if (a[0] == b[0]) {
                // 如果二者于同一位置开始，那么谁后结束，谁排在前
                return a[1] > b[1];
            } else {
                return 0;
            }
        });

        // 输出排序后的 points
        // for (const vector<int> &p : points) {
        //     cout << '[' << p[0] << ',' << p[1] << ']' << ", ";
        // }
        // cout << endl;

        // 通过记录「合并区间」后的开始位置和结束位置，来计算需要多少只箭
        // 注：这里「合并区间」不用真合并，只需要每次判断新的区间的 start 是否在 当前记录的连续区间的 end 之前即可
        // 「合并时」，合并后的 start = max(start1, start2), end = min(end1, end2)
        int start = points[0][0];
        int end = points[0][1];
        int arrows = 1;
        for (int i = 1; i < size; i++) {
            const vector<int> p = points[i];
            if (p[0] <= end) {  // 注意：根据题意，这里需要加上 = 号
                // 当前区间与之前合并或非合并后的区间有重叠，更新合并后的 start, end
                start = max(start, p[0]);
                end = min(end, p[1]);
            } else {
                // 当前区间与之前的区间没有重叠，更新当前区间的起始为新的 start, end，并递增 arrows
                start = p[0];
                end = p[1];
                arrows ++;
            }
        }

        return arrows;

    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394

