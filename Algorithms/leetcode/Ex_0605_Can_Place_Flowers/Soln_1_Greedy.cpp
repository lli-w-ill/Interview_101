#include <vector>

using std::vector;

class Solution_1 {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        if (size == 0) {
            return n == 0;
        } 

        int cnt = 0;    // 数还能种多少花
        for (int i = 0; i < size; i++) {
            bool noFlowerBefore = (i - 1 >= 0 ? flowerbed[i-1] == 0 : true);    // 如果越界了就默认为true
            bool noFlowerAfter = (i + 1 < size ? flowerbed[i+1] == 0 : true);   // 如果越界了就默认为true
            bool canPlant = (flowerbed[i] == 0);

            if (canPlant && noFlowerBefore && noFlowerAfter) {
                cnt ++;
                flowerbed[i] = 1;
            }
        }

        // 输出填 1 后的 flowerbed
        // for (const int &i : flowerbed) {
        //     cout << i << " ";
        // }
        // cout << endl;
        // cout << cnt << " " << n << endl;

        return cnt >= n;
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
// 贪心策略：越早种花越能给后面多留位置种花

