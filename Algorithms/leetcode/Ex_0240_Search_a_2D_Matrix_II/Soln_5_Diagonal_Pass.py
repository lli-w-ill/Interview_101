class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        # 特判
        if not matrix or len(matrix) == 0 or len(matrix[0]) == 0:
            return False

        rows = len(matrix)
        cols = len(matrix[0])

        r = rows - 1
        c = 0
        while c < cols and r >= 0:
            if matrix[r][c] == target:
                return True
            elif matrix[r][c] < target:
                # go right
                c += 1
            elif matrix[r][c] > target:
                # go up
                r -= 1
        return False

# 参考题解：https://leetcode-cn.com/problems/search-a-2d-matrix-ii/solution/sou-suo-er-wei-ju-zhen-ii-by-leetcode-2/
# 与 Soln_1 不同的是，这个解法从左下角往右上角，而 Soln_1 是从右上角往左下角
# 时间复杂度：O(n + m)
# 空间复杂度：O(1)
