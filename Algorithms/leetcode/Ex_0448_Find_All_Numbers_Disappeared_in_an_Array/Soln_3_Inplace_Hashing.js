/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDisappearedNumbers = function(nums) {
    var n = nums.length;
    var i;
    for (i = 0; i < n; i++) {
        // index 是 nums[i] 最终应该出现的地方
        var index = nums[i] - 1;
        // 多次交换直到
        while (nums[index] != nums[i]) {
            // 三变量法交换
            // var temp = nums[i];
            // nums[i] = nums[index];
            // nums[index] = temp;
            // >= ES6 交换
            [nums[i], nums[index]] = [nums[index], nums[i]];

            // update index
            index = nums[i] - 1;
        }
    }

    var res = [];
    // 再扫描 nums，将不符合 nums[i] = i + 1 的数字加入到 res
    for (i = 0; i < n; i++) {
        if (nums[i] !== i + 1) {
            res.push(i + 1);
        }
    }
    return res;
};

// 参考题解（非常推荐）：https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/solution/li-yong-tong-pai-xu-de-si-lu-ni-huan-ke-e3t4w/
// 建议和这道题一起做：https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/
