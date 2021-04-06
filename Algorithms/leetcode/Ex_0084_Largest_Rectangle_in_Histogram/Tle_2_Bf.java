package Algorithms.leetcode.Ex_0084_Largest_Rectangle_in_Histogram;

class Tle_2 {
    public int largestRectangleArea(int[] heights) {
        int len = heights.length;
        if (len == 0) {
            return 0;
        }
        int res = 0;
        for (int i = 0; i < len; i++) {
            // 从i往左边看，一直到能延伸的最远处（且必须保证当前柱子i全部用上）
            int left = i;
            while (left > 0 && heights[left - 1] >= heights[i]) {
                left -= 1;
            }
            // 从i往右边看，一直到能延伸的最远处（且必须保证当前柱子i全部用上）
            int right = i;
            while (right < len - 1 && heights[right + 1] >= heights[i]) {
                right += 1;
            }
            int width = right - left + 1;
            int area = width * heights[i];
            if (area > res) {
                res = area;
            }
        }
        return res;
    }
}

// 参考：https://leetcode-cn.com/problems/largest-rectangle-in-histogram/solution/bao-li-jie-fa-zhan-by-liweiwei1419/
