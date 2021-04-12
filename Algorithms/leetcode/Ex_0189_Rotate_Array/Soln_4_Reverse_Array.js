/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
const reverse = function(nums, start, end) {
    while (start < end) {
        [nums[start++], nums[end--]] = [nums[end], nums[start]];
    }
}

var rotate = function(nums, k) {
    length = nums.length;
    k %= length;
    
    // 第一步：翻转整个数组
    reverse(nums, 0, length-1);

    // 第二步：翻转第一部分 nums[0 ... k-1]
    reverse(nums, 0, k-1);

    // 第三步：翻转第二部分 nums[k ... size-1]
    reverse(nums, k, length-1);
};

// 参考题解（非常推荐）：https://leetcode-cn.com/problems/rotate-array/solution/shu-zu-fan-zhuan-xuan-zhuan-shu-zu-by-de-5937/
// 建议配合参考的动画一起理解
