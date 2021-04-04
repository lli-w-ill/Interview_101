from collections import Counter


class Solution_1:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        if board is None or len(board) == 0:
            return True
        
        # 检查每行
        for r in range(len(board)):
            nums = []
            for c in range(len(board[r])):
                nums.append(board[r][c])
            if self.invalid(nums):
                return False
        
        # 检查每列
        for c in range(len(board[0])):
            nums = []
            for r in range(len(board)):
                nums.append(board[r][c])
            if self.invalid(nums):
                return False
        
        # 检查每个3x3宫格
        for r in range(0, len(board), 3):
            for c in range(0, len(board[r]), 3):
                nums = []
                for i in range(r, r + 3):
                    for j in range(c, c + 3):
                        nums.append(board[i][j])
                if self.invalid(nums):
                    return False

        return True

    def invalid(self, nums: List[str]) -> bool:
        nums = [int(n) for n in nums if n != '.']
        if len(nums) == 0:
            return False
        return Counter(nums).most_common()[0][1] > 1;
