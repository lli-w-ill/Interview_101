#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;
using std::move;
using std::rand;

class Solution_4 {
public:
    Solution_4(vector<int>& nums) {
        this->origin = move(nums);
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return origin;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        // apply Fisher-Yates 洗牌算法
        if (origin.empty()) {
            return vector<int> {};
        }
        
        int size = origin.size();
        vector<int> shuffled (origin);

        // 可以使用正向洗牌，也可以用反向洗牌
        // 反向洗牌
        for (int i = size - 1; i >= 0; i--) {
            swap(shuffled[i], shuffled[rand() % (i + 1)]);
        }

        // 正向洗牌
        // for (int i = 0; i < size; i++) {
        //     int pos = rand() % (size - i);
        //     swap(shuffled[i], shuffled[i + pos]);
        // }

        return shuffled;
    }

private:
    // 记录所有原数字
    vector<int> origin;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
