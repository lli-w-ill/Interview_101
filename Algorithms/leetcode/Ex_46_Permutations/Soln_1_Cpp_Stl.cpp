#include <vector>
#include <algorithm>    // next_permutation

using std::vector;
using std::next_permutation;

class Solution_1 {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int> > res;
        if (len == 0) {
            return res;
        }
        sort(nums.begin(), nums.end());
        do {
            res.push_back(nums);
        } while (next_permutation(&nums[0], &nums[0] + len));
        return res;
    }
};
