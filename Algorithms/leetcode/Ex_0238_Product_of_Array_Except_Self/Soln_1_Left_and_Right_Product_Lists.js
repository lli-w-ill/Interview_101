/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function(nums) {
    var len = nums.length;
    if (len == 0) {
        return [];
    }
    // leftProduct[i] 表示 nums[0 ... i-1] 所有数的乘积
    var leftProduct = [...Array(len)];
    // rightProduct[i] 表示 nums[i+1 ... len-1] 所有数的乘积
    var rightProduct = [...Array(len)];
    // 初始化leftProduct, rightProduct
    leftProduct[0] = 1;
    rightProduct[len-1] = 1;
    
    // fill leftProduct
    for (let i = 1; i < len; i++) {
        leftProduct[i] = leftProduct[i-1] * nums[i-1];
    }
    // fill rightProduct
    for (let i = len - 2; i >= 0; i--) {
        rightProduct[i] = rightProduct[i+1] * nums[i+1];
    }

    var res = [...Array(len)];
    for (let i = 0; i < len; i++) {
        res[i] = leftProduct[i] * rightProduct[i];
    }

    return res;
};
