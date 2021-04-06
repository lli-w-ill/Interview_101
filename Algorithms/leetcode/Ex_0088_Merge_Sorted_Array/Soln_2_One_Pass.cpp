#include <vector>

using std::vector;
using std::swap;

class Solution_2 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = nums1.size() - 1;
        m = m - 1;
        n = n - 1;
        while (n >= 0) {
            while (m >= 0 && nums1[m] >= nums2[n]) {
                swap(nums1[i], nums1[m]);
                i --;
                m --;
            }
            swap(nums2[n], nums1[i]);
            i --;
            n --;
        }
    }
};

// 参考题解：https://leetcode-cn.com/problems/merge-sorted-array/solution/88-by-ikaruga/
