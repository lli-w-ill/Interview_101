#include <vector>

using std::vector;

class Solution_1 {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        int min = INT_MAX;
        for (int i = 0; i < size; i++) {
            min = std::min(min, nums[i]);
        }
        return min;
    }
};
