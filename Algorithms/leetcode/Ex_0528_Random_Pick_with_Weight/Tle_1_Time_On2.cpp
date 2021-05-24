#include <vector>
#include <cstdlib>

using std::vector;
using std::rand;

class Tle_1 {
public:
    Tle_1(vector<int>& w) {
        for (int i = 0; i < w.size(); i++) {
            for (int j = 0; j < w[i]; j++) {
                places.push_back(i);
            }
        }
    }
    
    int pickIndex() {
        return places[rand() % places.size()];
    }

private:
    // 构造函数中 w[i] 是多少，places 中就有 w[i] 个 i 以表示 i 的权重（增加 i 被选上的概率）
    vector<int> places;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

// 设 N = w.size(), M = places.size()
// time complexity: O(N * M)
// space complexity: O(M)
