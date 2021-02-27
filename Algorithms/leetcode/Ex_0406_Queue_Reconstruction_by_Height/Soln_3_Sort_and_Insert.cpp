#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

class Solution_3 {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b) {
            // 先按身高逆序排序 [0]，如果身高相同，再按 k_i 排序
            if (a[0] == b[0]) {
                // 按照 [1] (k_i) 升序排序 （a[1]值大的就是大，应该排在后面，也就是返回“大”，应该返回 false）
                return a[1] > b[1] ? false : true;
            } else {
                // 按照 [0] (h_i) 降序排序（a[0]值大的反而“小”，应该排在前面，也就是返回“小”，应该返回 true）
                return a[0] > b[0] ? true : false;
            }
        });

        // 因为需要插入到res中，先初始化相同个空串
        vector<vector<int>> res (people.size());
        for (const vector<int> &p : people) {
            res.insert(res.begin() + p[1], p);
        }

        // 删除 res 中的空串
        int i = 0;
        while (i < res.size()) {
            if (res[i].size() == 0) {
                res.erase(res.begin() + i);
            } else {
                i += 1;
            }
        }
        
        return res;
    }
};

// 参考题解：https://leetcode-cn.com/problems/queue-reconstruction-by-height/solution/406-gen-ju-shen-gao-zhong-jian-dui-lie-java-xian-p/
// 参考评论@mrbear的代码
// c++ std::sort() comparaison function: https://en.cppreference.com/w/cpp/algorithm/sort
// return true if first < second; return false if first > second
