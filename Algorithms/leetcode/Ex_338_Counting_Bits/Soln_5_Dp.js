/**
 * @param {number} num
 * @return {number[]}
 */
var countBits = function(num) {
    var res = [...Array(num+1)].map(_ => 0);
    var i = 0;
    var b = 1;  // 2^0
    while (b <= num) {
        // generate [b, 2b) or [b, num] (if 2b >= num) from [0, b)
        // [0, 1) -(then)-> [1, 2) -(then)-> [2, 4) -(then)-> [4, 8) -(then)-> [8, 15) -(then)-> ...
        //   b=1              b=2              b=4              b=8              b=16
        //   (1)              (10)             (100)           (1000)           (10000)          ...
        while (i < b && i + b <= num) {
            // 状态转移方程: P(i+b) = P(i) + 1, b=2^m > i
            // 推导建议看题解中的方法二
            res[i + b] = res[i] + 1;    // +1 加的是最高位的1，因为 5 (101) 比 5+2^3 = 13 (1 101) 之差最高位的 1
            i += 1;
        }
        i = 0;      // reset i
        b <<= 1;    // b = 2b
    }
    return res;
};

// 参考题解：https://leetcode-cn.com/problems/counting-bits/solution/bi-te-wei-ji-shu-by-leetcode/

