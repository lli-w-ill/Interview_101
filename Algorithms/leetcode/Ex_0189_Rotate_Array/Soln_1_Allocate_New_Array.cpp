#include <vector>

using std::vector;

class Solution_1 {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> res;
        res.reserve(nums.size());

        int size = nums.size();
        k %= size;
        if (size == 1 || k == 0) {
            return;
        }

        for (int i = size-k, j = 0; j < size; i = (i + 1) % size, j++) {
            res[j] = nums[i];
        }

        for (int i = 0; i < size; i++) {
            nums[i] = res[i];
        }
    }
};

// 设 N = nums.size()
// 时间复杂度：O(N)
// 空间复杂度：O(N)
