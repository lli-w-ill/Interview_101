package Algorithms.leetcode.Ex_46_Permutations;

import java.util.List;
import java.util.ArrayList;
import java.util.Deque;
import java.util.ArrayDeque;

class Solution_3 {
    public List<List<Integer>> permute(int[] nums) {
        int len = nums.length;
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if (len == 0) {
            return res;
        }
        Deque<Integer> path = new ArrayDeque<Integer>();
        boolean[] used = new boolean[len];
        // 第三个参数表示当前递归到的层数
        // 也可以说是当前path中的元素树
        dfs(nums, len, 0, path, used, res);
        return res;
    }

    private void dfs(int[] nums, int len, int depth, Deque<Integer> path, boolean[] used, List<List<Integer>> res) {
        if (depth == len) {
            // 所以元素都已经在path中
            // 这里注意一定要添加path的拷贝，而不是path，因为当递归返回时，退回到root节点，path会被置空
            res.add(new ArrayList<Integer>(path));
            return;
        }
        
        for (int i = 0; i < len; i++) {
            if (used[i]) {
                continue;
            }
            path.addLast(nums[i]);
            used[i] = true;
            // 递归到下一层
            dfs(nums, len, depth + 1, path, used, res);
            // 状态重置 (回溯)
            used[i] = false;
            path.removeLast();
        }
    }
}

// 参考（非常推荐）：https://leetcode-cn.com/problems/permutations/solution/quan-pai-lie-by-leetcode-solution-2/
// 参考（强烈推荐）：https://leetcode-cn.com/problems/permutations/solution/hui-su-suan-fa-python-dai-ma-java-dai-ma-by-liweiw/
// 注意每个节点的状态、状态重置
// 当遍历的层数depth等于输入数组的长度，递归停止
// 时间复杂度：O(n * n!) s.t. n = nums.length
