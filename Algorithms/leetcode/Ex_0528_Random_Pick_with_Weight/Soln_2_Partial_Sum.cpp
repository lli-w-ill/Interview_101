#include <vector>
#include <iostream>     // ostream
#include <algorithm>    // lower_bound
#include <numeric>      // partial_sum
#include <cstdlib>      // rand

using std::vector;
using std::cout;
using std::endl;
using std::ostream;
using std::lower_bound;
using std::partial_sum;
using std::rand;

ostream& operator<< (ostream& out, const vector<int> &v) {
    out << "[ ";
    for (const int &num : v) {
        out << num << " ";
    }
    out << "]";
    return out;
}

class Solution_2 {
private:
    // 保存前缀和
    vector<int> sums;
public:
    Solution_2(vector<int>& w) {
        sums = move(w);
        // 求前缀和
        partial_sum(sums.begin(), sums.end(), sums.begin());

        cout << "sums: " << sums << endl;
    }
    
    int pickIndex() {
        int pos = (rand() % sums.back()) + 1;
        // lower_bound 用二分法找到值「将将大于」pos 的 iterator
        // 然后再减去 begin 的 iterator 获得二分法找到的下标
        return lower_bound(sums.begin(), sums.end(), pos) - sums.begin();
    }

};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
// partial_sum 文档：http://www.cplusplus.com/reference/numeric/partial_sum/?kw=partial_sum
// lower_bound 文档：http://www.cplusplus.com/reference/algorithm/lower_bound/?kw=lower_bound
