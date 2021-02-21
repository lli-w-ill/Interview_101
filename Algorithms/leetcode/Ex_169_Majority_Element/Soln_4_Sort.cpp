#include <vector>

using std::vector;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

// 参考其他账号之前提交的结果
// 时间复杂度：O(nlogn)
// 空间复杂度：O(logn)
