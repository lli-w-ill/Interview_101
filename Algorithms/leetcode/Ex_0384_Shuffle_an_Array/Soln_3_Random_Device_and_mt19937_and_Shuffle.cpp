#include <vector>
#include <random>   // std::random_defice, std::mt19937, std::shuffle

using std::vector;
using std::random_device;
using std::mt19937;
using std::shuffle;

class Solution_3 {
public:
    Solution_3(vector<int>& nums) {
        this->nums = nums;  // 初始化原始数字数组
        this->data = nums;  // 初始化随机后的数字数组
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        random_device rd;
        mt19937 g(rd());
        std::shuffle(data.begin(), data.end(), g);  // 需要用std:: 避免和当前方法名字冲突

        return data;
    }

private:
    // 记录所有原数字
    vector<int> nums;
    // 记录随机后的数字
    vector<int> data;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

// 参考题解：https://leetcode-cn.com/problems/shuffle-an-array/solution/zhong-gui-zhong-ju-384-da-luan-shu-zu-by-1slm/
// random_device documentation: https://www.cplusplus.com/reference/random/random_device/?kw=random_device
// mt19937 documentation: https://www.cplusplus.com/reference/random/mt19937/?kw=mt19937
// shuffle documentation: https://www.cplusplus.com/reference/algorithm/shuffle/?kw=shuffle

