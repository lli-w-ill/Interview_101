class Solution:
    def trap(self, height: List[int]) -> int:
        # boundary checking
        if len(height) == 0:
            return 0

        # find the hightest left at indices
        left_highest = [0] * len(height)
        left_highest[0] = height[0]
        for i in range(1, len(height)):
            left_highest[i] = max(left_highest[i-1], height[i])

        # find the highest right at indices
        right_highest = [0] * len(height)
        right_highest[-1] = height[-1]
        for i in range(len(height)-2, -1, -1):
            right_highest[i] = max(right_highest[i+1], height[i])

        water = 0
        for i in range(len(height)):
            water += min(left_highest[i], right_highest[i]) - height[i]
        return water
