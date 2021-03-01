/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var maxSlidingWindow = function(nums, k) {
    let deque = []; // 保存 nums 下标
    let res = [...Array(nums.length - k + 1)];
    let ri = 0;     // res index
    
    for (let i = 0; i < nums.length; i++) {
        // 当 deque 的大小等于 i-k
        if (deque && deque[0] == i - k) {
            deque.shift();  // 首元素出队
        }
        // remove smaller numbers in k range as they are useless
        while (deque && nums[deque[deque.length-1]] < nums[i]) {
            deque.pop();
        }
        deque.push(i);
        if (i >= k - 1) {
            res[ri] = nums[deque[0]];
            ri += 1;
        }
    }

    return res;
};

// 参考题解：https://leetcode.com/problems/sliding-window-maximum/discuss/65884/Java-O(n)-solution-using-deque-with-explanation
