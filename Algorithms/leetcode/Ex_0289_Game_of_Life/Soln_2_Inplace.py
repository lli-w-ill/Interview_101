class Solution_2:
    def __init__(self):
        self.directions = [
            [-1, -1],
            [-1, 0],
            [-1, 1],
            [0, 1],
            [1, 1],
            [1, 0],
            [1, -1],
            [0, -1]
        ]

    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        rows = len(board)
        if rows == 0:
            return
        cols = len(board[0])

        for r in range(rows):
            for c in range(cols):
                aliveCnt = self.countAliveCell(board, r, c, rows, cols)
                
                # 分类讨论
                if board[r][c] % 10 == 1:   # 个位数是原值
                    # 活细胞
                    if aliveCnt < 2:
                        # 1 -> 01 (0[死亡] 是更新后的结果，但是因为int，所以前导0删除) -> 1
                        continue
                    elif aliveCnt == 2 or aliveCnt == 3:
                        # 1 -> 11
                        board[r][c] = 11
                    elif aliveCnt > 3:
                        # 1 -> 01
                        continue
                elif board[r][c] % 10 == 0: # 个位数是原值
                    # 死细胞
                    if aliveCnt == 3:
                        # 0 -> 10
                        board[r][c] = 10
                    else:
                        # 0 -> 00 -> 0
                        continue
        
        # 最终同时更新结果，board 所有位置更新为十位数，如果只有一位数字则不变
        for r in range(rows):
            for c in range(cols):
                if board[r][c] >= 10:
                    board[r][c] = board[r][c] // 10 
                else:
                    if board[r][c] == 1:
                        # 1 -> 01 -> 0
                        board[r][c] = 0
                    else:
                        # 0 -> 00 -> 0
                        continue

    def countAliveCell(self, board: List[List[int]], r: int, c: int, rows: int, cols: int) -> int:
        cnt = 0
        for d in self.directions:
            newr = r + d[0]
            newc = c + d[1]
            if not self.outOfBound(board, newr, newc, rows, cols) and board[newr][newc] % 10 == 1:
                cnt += 1
        return cnt

    def outOfBound(self, board: List[List[int]], r: int, c: int, rows: int, cols: int) -> bool:
        return r < 0 or c < 0 or r >= rows or c >= cols;


# in-place 思路：用个位数表示原 board[r][c] 的值，用十位数表示更新之后的值

