/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDuplicates = function(nums) {
    let res = new Set();

    const swap = (nums, i, j) => {
        const temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    for (let i = 0; i < nums.length; i++) {
        while (nums[i] != nums[nums[i] - 1]) {
            swap(nums, i, nums[i] - 1);
        }
        if (i != nums[i] - 1) {
            res.add(nums[i]);
        }
    }

    return Array.from(res);
};

// 建议结合第 41，448 题 和 剑指offer 03题 一起做
