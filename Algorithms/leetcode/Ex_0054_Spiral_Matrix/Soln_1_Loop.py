class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix or len(matrix) == 0:
            return []
        
        rows = len(matrix)
        cols = len(matrix[0])

        res = []

        r = 0
        c = 0
        while 0 <= r < rows and 0 <= c < cols and matrix[r][c] != '#':
            # 向右
            while c < cols and matrix[r][c] != '#':
                res.append(matrix[r][c])
                matrix[r][c] = '#'  # 当前位置为「已访问」
                c += 1
            # 向左下移动一格（因为多向右移动了一格，所以需要向左移动一格；向下移动一格是为了给向下运动的初始化）
            c -= 1
            r += 1

            # 向下
            while r < rows and matrix[r][c] != '#':
                res.append(matrix[r][c])
                matrix[r][c] = '#'  # 当前位置为「已访问」
                r += 1
            # 向左上移动一格
            r -= 1
            c -= 1

            # 向左
            while c >= 0 and matrix[r][c] != '#':
                res.append(matrix[r][c])
                matrix[r][c] = '#'  # 当前位置为「已访问」
                c -= 1
            # 向右上移动一格
            r -= 1
            c += 1

            # 向上
            while r >= 0 and matrix[r][c] != '#':
                res.append(matrix[r][c])
                matrix[r][c] = '#'  # 当前位置为「已访问」
                r -= 1
            # 向右下移动一格
            r += 1
            c += 1
        
        return res
