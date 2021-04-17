#include <vector>
#include <algorithm>    // std::sort
#include <cmath>        // std::ceil

using std::vector;
using std::sort;
using std::ceil;

class Solution_1 {
public:
    void wiggleSort(vector<int>& nums) {
        if (nums.size() == 0) {
            return;
        }

        sort(nums.begin(), nums.end());

        vector<int> res;
        int size = nums.size();
        int mid = ceil(size / 2.0);
        int lo = mid - 1;
        int hi = size - 1;
        while (lo >= 0) {
            res.push_back(nums[lo]);
            lo --;

            if (hi < mid) {
                break;
            }

            res.push_back(nums[hi]);
            hi --;
        }

        nums = res;
    }
};

// 参考之前账号提交记录
