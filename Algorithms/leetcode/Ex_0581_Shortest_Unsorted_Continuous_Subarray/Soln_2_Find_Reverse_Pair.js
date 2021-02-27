/**
 * @param {number[]} nums
 * @return {number}
 */
// 找到 nums 中的最小值和最大值
function getMinMax(nums) {
    return nums.reduce(({min, max}, v) => ({
        min: min < v ? min : v,
        max: max > v ? max : v,
    }), {min: nums[0], max: nums[0]});        
}

var findUnsortedSubarray = function(nums) {
    // 定义反序相邻pair中的「最小值」和「最大值」
    var minmax = getMinMax(nums);
    var minValReversePair = minmax.max;
    var maxValReversePair = minmax.min;
    // console.log(minValReversePair, maxValReversePair);

    let len = nums.length
    // 找到「反序的相邻pair」中最小值和最大值
    for (let i = 0; i < len; i++) {
        if (i - 1 >= 0 && nums[i] < nums[i-1]) {
            // 前大后小，和前一个元素比
            minValReversePair = Math.min(minValReversePair, nums[i]);
        }
        if (i + 1 < len && nums[i] > nums[i+1]) {
            // 前大后小，和后一个元素比
            maxValReversePair = Math.max(maxValReversePair, nums[i]);
        }
    }
    // console.log(minValReversePair, maxValReversePair);

    // 从0开始往后找到第一个恰好比 minValReversePair 大的数的下标
    let l = 0;
    for (; l < len && nums[l] <= minValReversePair; l++) {
    }
    // 从len-1开始往前找到第一个恰好比 maxValReversePair 小的数的下标
    let r = len - 1;
    for (; r >= 0 && nums[r] >= maxValReversePair; r--) {
    }

    if (r > l) {
        return r - l + 1;
    } else {
        return 0;
    }    
};

// javascript 快速找到 array 中的最大数和最小数：https://stackoverflow.com/questions/1669190/find-the-min-max-element-of-an-array-in-javascript
// javascript reduce用法：https://www.freecodecamp.org/news/reduce-f47a7da511a9/
