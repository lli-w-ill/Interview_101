#include <vector>
#include <algorithm>    // std::swap

using std::vector;
using std::swap;

class Solution_2 {
public:
    void moveZeroes(vector<int>& nums) {
        int nextOverrideIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[nextOverrideIndex]);
                nextOverrideIndex += 1;   
            }
        }
    }
};
