package Algorithms.leetcode.Ex_0581_Shortest_Unsorted_Continuous_Subarray;

import java.util.Stack;

class Solution_6 {
    public int findUnsortedSubarray(int[] nums) {
        Stack<Integer> stack = new Stack<Integer>();
        int l = nums.length;
        int r = 0;
        // 从左向右扫描，寻找左边界
        for (int i = 0; i < nums.length; i++) {
            while (!stack.isEmpty() && nums[stack.peek()] > nums[i]) {
                // 不断弹栈，直到栈顶元素小于当前元素nums[i]
                l = Math.min(l, stack.pop());
            }
            stack.push(i);
        }
        // 从右向左扫描，寻找右边界
        stack.clear();
        for (int i = nums.length - 1; i >= 0; i--) {
            while (!stack.isEmpty() && nums[stack.peek()] < nums[i]) {
                // 不断弹栈，直到栈顶元素大于当前元素（因为栈顶元素在排序数组中应该出现在nums[i]的后边）
                r = Math.max(r, stack.pop());
            }
            stack.push(i);
        }
        return l < r ? r - l + 1 : 0;
    }
}

// 参考题解：https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/solution/zui-duan-wu-xu-lian-xu-zi-shu-zu-by-leetcode/
// 思路：感觉像单调栈的思路 Monotone Stack

