#include <vector>

using std::vector;

class Tle_2 {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> res;
        res.reserve(nums.size());

        int size = nums.size();
        k %= size;
        if (size == 1 || k == 0) {
            return;
        }

        for (int i = 0; i < k; i++) {
            moveRightByOne(nums);
        }
    }

private:
    void moveRightByOne(vector<int> &nums) {
        int last = nums[nums.size() - 1];
        for (int i = nums.size() - 1; i > 0; i--) {
            nums[i] = nums[i-1];
        }
        nums[0] = last;
    }
};
