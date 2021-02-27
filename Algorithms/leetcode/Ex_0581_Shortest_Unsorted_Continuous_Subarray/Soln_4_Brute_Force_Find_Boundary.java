package Algorithms.leetcode.Ex_0581_Shortest_Unsorted_Continuous_Subarray;

class Solution_4 {
    public int findUnsortedSubarray(int[] nums) {
        int l = nums.length;    // 无序子序例的左边界
        int r = 0;              // 无序子序列的右边界
        for (int i = 0; i < nums.length - 1; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[j] < nums[i]) {
                    // nums[i], nums[j] 都不在其正确的位置上
                    l = Math.min(l, i);
                    r = Math.max(r, j);
                }
            }
        }
        return r >= l ? r - l + 1 : 0;
    }
}

// 参考题解：https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/solution/zui-duan-wu-xu-lian-xu-zi-shu-zu-by-leetcode/
// 思路：如果存在 nums[j]nums[j] 比 nums[i]nums[i] 小，这意味着 nums[i]nums[i] 和 nums[j]nums[j] 都不在排序后数组中的正确位置。因此我们需要交换这两个元素使它们到正确的位置上。但这里我们并不需要真的交换两个元素，我们只需要标记两个元素在原数组中的位置 ii 和 jj 。这两个元素标记着目前无序数组的边界。

// 作者：LeetCode
// 链接：https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/solution/zui-duan-wu-xu-lian-xu-zi-shu-zu-by-leetcode/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
