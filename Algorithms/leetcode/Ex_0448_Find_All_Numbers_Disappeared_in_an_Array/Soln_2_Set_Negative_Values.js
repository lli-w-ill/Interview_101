/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDisappearedNumbers = function(nums) {
    var i;
    for (i = 0; i < nums.length; i++) {
        // 注意这里一定要取绝对值，因为nums中的数字有可能已经被置反了
        var index = Math.abs(nums[i]) - 1;
        // 这里先取绝对值，再置反是因为如果一个数字重复出现偶数次，那么这个数字会将对应下标的数字置反偶数次，相当于没有置反
        nums[index] = -1 * Math.abs(nums[index]);
    }

    var res = [];
    for (i = 0; i < nums.length; i++) {
        if (nums[i] > 0) {
            var actualNum = i + 1;
            res.push(actualNum);
        }
    }

    return res;
};
