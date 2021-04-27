#include <vector>

using std::vector;
using std::min;
using std::max;

class Solution_4 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        if (n > m) {
            // 保证 nums1 较短
            return findMedianSortedArrays(nums2, nums1);
        }

        int LMax1;      // nums1 的“割”左边的最大数
        int LMax2;      // nums2 的“割”左边的最大数
        int RMin1;      // nums1 的”割“右边的最小数
        int RMin2;      // nums2 的“割”右边的最小数
        int c1;         // nums1 的“割”
        int c2;         // nums2 的“割”
        int lo = 0;     // nums1 的左边界
        int hi = 2 * n;     // 虚拟加 # 后，nums1 的长度为 2*n

        // 开始二分
        while (lo <= hi) {
            c1 = lo + (hi - lo) / 2;
            c2 = m + n - c1;

            LMax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
            RMin1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2];
            LMax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
            RMin2 = (c2 == 2 * m) ? INT_MAX : nums2[c2 / 2];

            if (LMax1 > RMin2) {
                hi = c1 - 1;
            } else if (LMax2 > RMin1) {
                lo = c1 + 1;
            } else {
                break;
            }
        }

        return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;

    }
};

// 参考题解：https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/4-xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-shu/
