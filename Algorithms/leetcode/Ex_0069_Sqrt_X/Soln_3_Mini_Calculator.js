/**
 * @param {number} x
 * @return {number}
 */
var mySqrt = function(x) {
    if (x == 0)
        return 0;
    
    // sqrt(x) = e ^ {1/2 * log_e(x)} = e ^ {1/2 * ln(x)}
    res = Math.floor(Math.exp(0.5 * Math.log(x)));

    if ((res + 1) ** 2 <= x)
        return res + 1;
    else
        return res;
};

// 参考题解：https://leetcode-cn.com/problems/sqrtx/solution/x-de-ping-fang-gen-by-leetcode-solution/

