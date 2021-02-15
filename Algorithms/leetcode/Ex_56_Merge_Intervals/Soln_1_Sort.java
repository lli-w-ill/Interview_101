package Algorithms.leetcode.Ex_56_Merge_Intervals;

import java.util.Arrays;
import java.util.Stack;

class Solution_1 {
    public int[][] merge(int[][] intervals) {
        if (intervals.length == 0) {
            return new int[0][0];
        }
        Arrays.sort(intervals, java.util.Comparator.comparingDouble(o -> o[0]));
        Stack<int[]> merge = new Stack<int[]>();
        for (int[] inter : intervals) {
            if (!merge.isEmpty() && inter[0] <= merge.peek()[1]) {
                // 合并inter与merge.peek()
                int[] top = merge.pop();
                top[1] = Math.max(inter[1], top[1]);
                merge.push(top);
            } else {
                merge.push(inter);
            }
        }
        int[][] res = new int[merge.size()][2];
        int idx = merge.size() - 1;
        while (!merge.isEmpty()) {
            res[idx] = merge.pop();
            idx -= 1;
        }
        return res;
    }
}

// 二维数组排序：https://stackoverflow.com/questions/15452429/java-arrays-sort-2d-array
// List<int[]:
// https://stackoverflow.com/questions/13665188/arraylist-of-integer-arrays-in-java/13665239