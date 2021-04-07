class Solution_2:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        preRow = [0 for _ in range(len(text2) + 1)]
        
        for i in range(1, len(text1) + 1):
            curRow = [0 for _ in range(len(text2) + 1)]
            for j in range(len(text2) + 1):
                if j == 0:
                    curRow[j] = 0
                elif text1[i-1] == text2[j-1]:
                    curRow[j] = preRow[j-1] + 1
                else:
                    curRow[j] = max(curRow[j-1], preRow[j])
            # 滑窗向下移动，更新preRow
            preRow = curRow

        return curRow[-1]
