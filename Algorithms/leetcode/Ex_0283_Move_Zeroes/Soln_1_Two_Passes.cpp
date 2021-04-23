#include <vector>

using std::vector;

class Solution_1 {
public:
    void moveZeroes(vector<int>& nums) {
        int nextOverrideIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                continue;
            } else {
                nums[nextOverrideIndex++] = nums[i];
            }
        }
        // 所有非零数字都已经复写到前面了，只需要将nums[nextOverrideIndex ... END] 都设成0就可以
        for (int i = nextOverrideIndex; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};
