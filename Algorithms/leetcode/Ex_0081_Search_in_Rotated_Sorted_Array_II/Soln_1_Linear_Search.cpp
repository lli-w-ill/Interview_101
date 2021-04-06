#include <vector>

using std::vector;

class Solution_1 {
public:
    bool search(vector<int>& nums, int target) {
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (nums[i] == target) {
                return true;
            }
        }
        return false;
    }
};
