/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function(nums) {
    var len = nums.length;
    if (len == 0) {
        return [];
    }
    var res = [...Array(len)];
    // 初始化 res 为 Soln_1 中的 leftProduct
    res[0] = 1;
    for (let i = 1; i < len; i++) {
        res[i] = res[i-1] * nums[i-1];
    }
    
    // 用一个变量动态计算 rightProduct on the fly，而不保存到一个数组中
    rightProduct = 1;
    for (let i = len - 1; i >= 0; i--) {
        res[i] = res[i] * rightProduct;
        rightProduct *= nums[i];
    }

    return res;
};
