#include <vector>

using std::vector;

class Solution_1 {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int res = 0;

        // 首先和 0 ~ n 的所有数异或
        for (int i = 0; i <= size; i++) {
            res ^= i;
        }
        // 然后再和 nums 中所有数字异或（双数异或会抵消，所以最后剩的数字一定是丢失的数）
        for (const int &num : nums) {
            res ^= num;
        }
        
        return res;
    }
};
