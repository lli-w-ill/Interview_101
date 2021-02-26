/**
 * @param {number[]} nums
 * @return {number}
 */
var findRepeatNumber = function(nums) {
    const len = nums.length;
    for (let i = 0; i < len; i++) {
        // 检查下标 i 的元素 (nums[i]) 是否放在了位置(或下标)i上
        // 注意：因为题目说明了数组中所有数字都在 [0, len-1] 之间，所以才有这个性质。如果所有数字都在 [1, len] 之间，那么就需要有 1 的offset（详见Ex448. 找到所有数组中消失的数字）
        while (nums[i] !== i) { // 如果 nums[i] 已经出现在了下标i处，说明它已经在它应该在的地方了
            // console.log(nums, i);
            if (nums[i] === nums[nums[i]]) {
                return nums[i];
            } else {
                // 三变量法交换 (okay)
                var temp = nums[i];
                nums[i] = nums[nums[i]];
                nums[temp] = temp;

                // [nums[i], nums[nums[i]]] = [nums[nums[i]], nums[i]]; // this is wrong (无限循环)

                // [nums[nums[i]], nums[i]] = [nums[i], nums[nums[i]]]; // this is okay
            }
        }
        // console.log("===============");
    }
};

// 参考题解（强烈推荐）：https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/solution/cong-qian-ru-shen-ha-xi-biao-yuan-di-ha-xi-kong-ji/
