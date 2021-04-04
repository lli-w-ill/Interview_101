/**
 * @param {number[]} nums
 * @return {number}
 */
var firstMissingPositive = function(nums) {
    // 特判
    if (nums.length == 0) {
        return 1;
    }

    let set = new Set();
    for (let i = 0; i < nums.length; i++) {
        set.add(nums[i]);
    }

    let INT_MAX = 2 ** 31 - 1;
    for (let i = 1; i <= INT_MAX; i++) {
        // console.log(i, set.has(i));
        if (!set.has(i)) {
            return i;
        }
    }
};
