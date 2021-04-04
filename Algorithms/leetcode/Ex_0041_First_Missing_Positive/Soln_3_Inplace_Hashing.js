/**
 * @param {number[]} nums
 * @return {number}
 */

var firstMissingPositive = function(nums) {
    
    const len = nums.length;
    const swap = (nums, i, j) => {
        const temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    for (let i = 0; i < len; i++) {
        while (nums[i] > 0 && nums[i] != nums[nums[i] - 1]) {
            swap(nums, i, nums[i] - 1);
        }
    }

    for (let i = 0; i < len; i++) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    return len + 1;
};

// 参考题解（非常推荐）：https://leetcode-cn.com/problems/first-missing-positive/solution/tong-pai-xu-python-dai-ma-by-liweiwei1419/
// 时间复杂度：O(n) -- 分摊分析
// 空间复杂度：O(1)
