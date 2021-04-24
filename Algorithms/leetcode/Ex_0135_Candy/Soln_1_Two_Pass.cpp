#include <vector>
#include <numeric>
#include <algorithm>

using std::vector;
using std::accumulate;
using std::max;

class Solution_1 {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        if (size == 0 || size == 1) {
            return size;
        }

        // 初始化每个孩子都分到一个糖果
        vector<int> count (size, 1);

        // 从左到右遍历
        // 保证了从左往右方向上，如果后一个孩子评分比当前孩子评分高，那么分到的糖果也多
        for (int i = 0; i < size - 1; i++) {
            if (ratings[i+1] > ratings[i]) {
                count[i+1] = count[i] + 1;
            }
        }

        // 从右往左遍历
        // 保证了从右往左方向上，如果前一个孩子评分比当前孩子评分高，那么分到的糖果也多
        for (int i = size - 1; i > 0; i--) {
            if (ratings[i-1] > ratings[i]) {
                // 这里要取 max，因为要保证上面「从左到右遍历时构建的条件不变」的条件下，构建「从右向左看的条件」
                count[i-1] = max(count[i-1], count[i] + 1);
            }
        }

        return accumulate(count.begin(), count.end(), 0);
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
