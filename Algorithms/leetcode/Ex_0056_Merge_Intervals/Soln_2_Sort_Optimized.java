package Algorithms.leetcode.Ex_0056_Merge_Intervals;

import java.util.Arrays;

class Solution {
    public int[][] merge(int[][] intervals) {
        if (intervals.length == 0) {
            return new int[0][0];
        }
        Arrays.sort(intervals, (v1, v2) -> v1[0] - v2[0]);
        int[][] res = new int[intervals.length][2];
        int idx = -1; // 指向当前res的最后一个元素
        for (int[] inter : intervals) {
            if (idx == -1 || inter[0] > res[idx][1]) {
                // 没有重合，直接加入到res
                res[++idx] = inter;
            } else {
                // 有重合，更新res最后一个区间的右边界
                res[idx][1] = Math.max(inter[1], res[idx][1]);
            }
        }
        // res只有0...idx是有效的，所以第二个参数是长度，应该为idx+1
        return Arrays.copyOf(res, idx + 1);
    }
}

// 参考：https://leetcode-cn.com/problems/merge-intervals/solution/chi-jing-ran-yi-yan-miao-dong-by-sweetiee/
