#include <vector>
#include <cstdlib>  // std::rand, std::srand

using std::vector;
using std::rand;
using std::srand;
using std::swap;

class Solution_2 {
public:
    Solution_2(vector<int>& nums) {
        // 拷贝
        this->nums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> data (nums);    // 创建一份拷贝
        for (int i = 0; i < data.size(); i++) {
            int t = i + (rand() % (nums.size() - i));
            swap(data[i], data[t]);
        }

        return data;
    }

private:
    // 记录所有数字
    vector<int> nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

// 参考题解：https://leetcode-cn.com/problems/shuffle-an-array/solution/zhong-gui-zhong-ju-384-da-luan-shu-zu-by-1slm/
