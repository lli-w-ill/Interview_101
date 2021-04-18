class Solution_6:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        # 特判
        if not matrix:
            return False
        
        # 从左下角到「能到达不越界的最右上角」进行迭代二分搜索
        rows = len(matrix)
        cols = len(matrix[0])
        for i in range(min(rows, cols)):
            vertical_found = self.binarySearch(matrix, target, i, True)
            horizontal_found = self.binarySearch(matrix, target, i, False)
            if vertical_found or horizontal_found:
                return True
        
        return False

    def binarySearch(self, matrix: List[List[int]], target: int, start: int, searchVertical: bool) -> bool:
        lo = start
        # 如果是搜列，则最大的hi是行数；如果是搜行，则最大的hi是列数
        hi = len(matrix[0]) - 1 if searchVertical else len(matrix) - 1

        while hi >= lo:
            mid = lo + (hi - lo) // 2
            if searchVertical:
                # 搜当前 start 列
                if matrix[start][mid] < target:
                    lo = mid + 1
                elif matrix[start][mid] > target:
                    hi = mid - 1
                elif matrix[start][mid] == target:
                    return True
            else:
                # 搜当前 start 行
                if matrix[mid][start] < target:
                    lo = mid + 1
                elif matrix[mid][start] > target:
                    hi = mid - 1
                elif matrix[mid][start] == target:
                    return True
        return False

# 参考题解：https://leetcode-cn.com/problems/search-a-2d-matrix-ii/solution/sou-suo-er-wei-ju-zhen-ii-by-leetcode-2/

