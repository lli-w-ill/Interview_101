package Algorithms.leetcode.Ex_84_Largest_Rectangle_in_Histogram;

import java.util.Deque;
import java.util.ArrayDeque;

class Solution_3 {
    public int largestRectangleArea(int[] heights) {
        int len = heights.length;
        if (len == 0) {
            return 0;
        }
        if (len == 1) {
            return heights[0];
        }
        int res = 0;
        Deque<Integer> stack = new ArrayDeque<Integer>(len);
        for (int i = 0; i < len; i++) {
            // 如果当前柱子的高度要矮于上一个数字的高度时，上一个柱子的宽度就可以被确定下来，就可以计算其面积
            while (!stack.isEmpty() && heights[i] < heights[stack.peekLast()]) {
                // 上一个柱子的高度
                int curHeight = heights[stack.pollLast()];
                // 如果上一个柱子之前有和其紧挨着，并且高度相同的柱子，也出栈
                while (!stack.isEmpty() && heights[stack.peekLast()] == curHeight) {
                    stack.pollLast();
                }
                // 计算上一个柱子构成矩形的宽度
                int curWidth;
                if (stack.isEmpty()) {
                    curWidth = i;
                } else {
                    curWidth = i - stack.peekLast() - 1;
                }
                res = Math.max(res, curHeight * curWidth);
            }
            stack.addLast(i);
        }

        // 依然在栈中的元素，依次出栈
        while (!stack.isEmpty()) {
            int curHeight = heights[stack.pollLast()];
            while (!stack.isEmpty() && heights[stack.peekLast()] == curHeight) {
                stack.pollLast();
            }
            int curWidth;
            if (stack.isEmpty()) {
                curWidth = len;
            } else {
                curWidth = len - stack.peekLast() - 1;
            }
            res = Math.max(res, curHeight * curWidth);
        }
        return res;
    }
}

// 参考：https://leetcode-cn.com/problems/largest-rectangle-in-histogram/solution/bao-li-jie-fa-zhan-by-liweiwei1419/
