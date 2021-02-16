package Algorithms.leetcode.Ex_11_Container_With_Most_Water;

class Solution_1 {
    public int maxArea(int[] height) {
        int len = height.length;
        int maxArea = 0;
        for (int l = 0; l < len; l++) {
            int area = 0;
            for (int r = l + 1; r < len; r++) {
                int w = r - l;
                int h = Math.min(height[l], height[r]);
                area = Math.max(w * h, area);
            }
            maxArea = Math.max(area, maxArea);
        }
        return maxArea;
    }
}
