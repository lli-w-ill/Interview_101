/**
 * @param {number[]} nums
 * @return {number}
 */
var firstMissingPositive = function(nums) {
    nums.sort((a, b) => a - b);
    console.log(nums);

    // 找到排序后 nums 正数开始时的下标
    let start = 0;
    for (; nums[start] <= 0; start++) {
    }

    let INT_MAX = 2 ** 31 - 1; 
    for (let i = 1; i <= INT_MAX; i++, start++) {
        // start到下一个非重复的数字
        while (start != 0 && nums[start] == nums[start - 1]) {
            start++;
        }
        
        if (nums[start] != i) {
            return i;
        }
    }
    
    return nums[-1] + 1;
};
