/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permuteUnique = function(nums) {
    const res = []
    const used = new Array(nums.length);
    nums.sort((a, b) => a - b); // 先升序排列

    const helper = (path) => {
        if (path.length == nums.length) {
            res.push(path.slice()); // 加入 path 的一份拷贝
            return;
        }

        for (let i = 0; i < nums.length; i++) {
            if (used[i]) {
                // 当前位已经被用过了
                continue;
            }
            if (i - 1 >= 0 && nums[i-1] == nums[i] && !used[i-1]) {
                // nums[i-1] 位存在，且与当前下标的值相同，且已经被用过了
                // 这时需要去重
                // 举例：[1(1), 1(2), 2]   // 这里()内表示第几个1，方便区分
                // 当遍历完第一层的 1(1)，之后遍历到「参考题解」中截图中第一层的 1(2) 时，可以发现 「1(1)作为第一个数」 和 「1(2)作为第一个数」下面的结果是完全重复的，所以此时需要跳过 1(2) 作为第一层的选择，遍历第一层的 2下面的选择
                // 
                continue;
            }

            // 修改当前节点状态
            path.push(nums[i]);
            used[i] = true;

            // 递归子节点
            helper(path);

            // 恢复当前节点状态
            used[i] = false;
            path.pop();
        }
    }

    helper([]);
    return res;
};

// 参考题解（非常推荐）：https://leetcode-cn.com/problems/permutations-ii/solution/shou-hua-tu-jie-li-yong-yue-shu-tiao-jian-chong-fe/

