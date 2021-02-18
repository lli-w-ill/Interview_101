package Algorithms.leetcode.Ex_39_Combination_Sum;

import java.util.List;
import java.util.ArrayList;
import java.util.Deque;
import java.util.ArrayDeque;

class Solution_2 {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        int len = candidates.length;
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if (len == 0) {
            return res;
        }
        Deque<Integer> path = new ArrayDeque<Integer>();
        dfs(candidates, 0, len, target, path, res);
        return res;
    }

    private void dfs(int[] nums, int startIdx, int len, int target, Deque<Integer> path, List<List<Integer>> res) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            res.add(new ArrayList<Integer>(path));
            return;
        }
        for (int i = startIdx; i < len; i++) {
            path.addLast(nums[i]);
            dfs(nums, i, len, target - nums[i], path, res);    // 将i当作参数防止重复，因为下一次依然可以用当前数字，所以传入i而不是i+1
            path.removeLast();  // 状态重置
        }
    }
}

// 注：实际上 backtracking 大部分情况下就是对一棵树的遍历
// 参考（非常推荐）：https://leetcode-cn.com/problems/combination-sum/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-m-2/
