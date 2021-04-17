#include <vector>

using std::vector;

class Solution_3 {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return nums[0];
        }
        return divideAndConquer(nums, 0, n - 1);
    }

private:
    int divideAndConquer(const vector<int> &nums, int lo, int hi) {
        if (lo == hi) {
            // 当前范围只有一个元素，那么它肯定就是 majority 元素
            return nums[lo];
        }
        // 选取终点
        int mid = lo + (hi - lo) / 2;
        // 求 nums[left ... mid] 的 majority 元素是什么
        int leftMajority = divideAndConquer(nums, lo, mid);
        // 求 nums[mid+1 ... right] 的 majority 元素是什么
        int rightMajority = divideAndConquer(nums, mid + 1, hi);

        if (leftMajority == rightMajority) {
            return leftMajority;
        } else {
            // 说明 nums 左半边和右半边 majority 元素不同，那么就要在 nums[lo ... hi] 分别数 leftMajority 和 rightMajority 分别出现多少次，然后返回出现次数更多的那个数
            int leftMajorityFreq = countInRange(nums, lo, hi, leftMajority);
            int rightMajorityFreq = countInRange(nums, lo, hi, rightMajority);
            return leftMajorityFreq >= rightMajorityFreq ? leftMajority : rightMajority;
        }
    }

    int countInRange(const vector<int> &nums, int lo, int hi, int target) {
        int count = 0;
        for (int i = lo; i <= hi; i++) {
            if (nums[i] == target) {
                count += 1;
            }
        }
        return count;
    }
};

// 参考其他账号之前提交的结果
// 时间复杂度：根据主定理(Master Theorem)，求得 T(n) = 2T(n/2) + 2n 的时间复杂度为 O(nlogn)（+2n 是因为最坏情况要做两遍O(n)的线性扫描）
// 空间复杂度：O(1)

