#include <vector>
#include <algorithm>

using std::vector;
using std::next_permutation;

class Solution_2 {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) {
            return;
        }
        next_permutation(&nums[0], &nums[0] + len);
    }
};


// STL参考：http://www.cplusplus.com/reference/algorithm/next_permutation/