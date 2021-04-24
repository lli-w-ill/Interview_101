#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

class Solution_4 {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 先按照 h_i 再按照 k_i 对 people 进行排序
        sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b) -> int {
            if (a[0] > b[0]) {
                // a 比 b 高，那么排序后让 a 在 b 前面
                return 1;
            } else if (a[0] == b[0]) {
                // 如果 a b 相同高，那么根据 k 排序，k 小的排在前
                return a[1] < b[1];
            } else if (a[1] < b[1]) {
                return 0;
            }
            return 0;
        });

        // 输出排序后的数组
        // for (const vector<int> &p : people) {
        //     cout << '[' << p[0] << ',' << p[1] << ']' << ", ";
        // }
        // cout << endl;

        int size = people.size();
        vector<vector<int>> res;
        for (int i = 0; i < size; i++) {
            res.insert(res.begin() + people[i][1], people[i]);
        }

        return res;
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394

