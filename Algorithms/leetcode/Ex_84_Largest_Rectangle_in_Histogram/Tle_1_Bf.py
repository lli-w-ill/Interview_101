class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        if not heights:
            return 0
        # 计算从heights[i...j]之间的最低的柱子高度
        lowest = {}
        for i in range(len(heights)):
            low = heights[i]
            for j in range(i, len(heights)):
                if heights[j] < low:
                    low = heights[j]
                lowest[(i, j)] = low
        # 计算最大的矩形面积
        maxArea = 0
        for i in range(len(heights)):
            currMaxArea = 0
            for j in range(i, len(heights)):
                area = lowest[(i, j)] * (j - i + 1)
                if area > currMaxArea:
                    currMaxArea = area
            if currMaxArea > maxArea:
                maxArea = currMaxArea
        return maxArea
