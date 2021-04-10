/**
 * @param {number[]} gas
 * @param {number[]} cost
 * @return {number}
 */
var canCompleteCircuit = function(gas, cost) {
    const len = gas.length;
    let spare = 0;  // 总剩油量
    let minSpare = Number.MAX_SAFE_INTEGER; // 记录最少省油量
    let minIndex = 0;   // 记录最少省油量时的加油站下标

    for (let i = 0; i < len; i++) {
        spare += gas[i] - cost[i];
        if (spare < minSpare) {
            minSpare = spare;
            minIndex = i;
        }
    }

    // 如果总省油量小于0，说明肯定不能走一圈
    // 否则，从最少省油量时的加油站的下一加油站开始，一定可以走完一圈
    return spare < 0 ? -1 : (minIndex + 1) % len;
};

// 参考题解：https://leetcode-cn.com/problems/gas-station/solution/shi-yong-tu-de-si-xiang-fen-xi-gai-wen-ti-by-cyayc/
// 设 N = len(gas)
// 时间复杂度：O(N)
// 空间复杂度：O(1)
