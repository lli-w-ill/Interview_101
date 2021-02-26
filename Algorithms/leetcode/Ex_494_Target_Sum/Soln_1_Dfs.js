/**
 * @param {number[]} nums
 * @param {number} S
 * @return {number}
 */
var res;

function dfs(nums, len, index, curSum, targetSum) {
    // base case
    if (index === len) {
        if (curSum === targetSum) {
            res += 1;
        }
        return;
    }

    dfs(nums, len, index + 1, curSum + nums[index], targetSum);

    dfs(nums, len, index + 1, curSum - nums[index], targetSum);
}

var findTargetSumWays = function(nums, S) {
    res = 0;
    dfs(nums, nums.length, 0, 0, S);
    return res;
};
