/**
 * @param {number[]} nums
 * @return {number}
 */
var findRepeatNumber = function(nums) {
    let map = new Map();

    for (const num of nums) {
        if (!map.has(num)) {
            map.set(num, true);
        } else {
            return num;
        }
    }
};

// 参考题解（强烈推荐）：https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/solution/cong-qian-ru-shen-ha-xi-biao-yuan-di-ha-xi-kong-ji/
