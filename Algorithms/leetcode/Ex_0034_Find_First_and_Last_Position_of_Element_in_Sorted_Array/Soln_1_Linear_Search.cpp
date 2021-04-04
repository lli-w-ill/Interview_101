#include <vector>

using std::vector;

class Solution_1 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        int start = -1;
        int end = -1;
        for (int i = 0; i < len; i++) {
            if (nums[i] == target) {
                if (start == -1) {
                    start = i;
                }
                if (start != -1) {
                    end = i;
                }
            }
        }
        vector<int> res {start, end};
        return res;
    }
};
