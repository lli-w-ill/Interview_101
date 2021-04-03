/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    let slow = 0;
    let fast = 1;
    while (fast < nums.length) {
        if (nums[slow] == nums[fast]) {
            fast += 1;
        } else {
            nums[slow + 1] = nums[fast];
            slow += 1;
            fast += 1;
        }
    }
    return slow + 1;
};
