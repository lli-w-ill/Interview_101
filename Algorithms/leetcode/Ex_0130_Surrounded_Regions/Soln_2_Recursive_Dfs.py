class Solution_2:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        m = len(board)
        n = len(board[0])

        # 扫第一遍
        for i in range(m):
            for j in range(n):
                isEdge = (i == 0 or j == 0 or i == m-1 or j == n-1)
                if isEdge and board[i][j] == 'O':
                    self.dfs(board, m, n, i, j)
        
        # 扫第二遍
        for i in range(m):
            for j in range(n):
                if board[i][j] == 'O':
                    board[i][j] = 'X'   # (i, j) 一定是中间被 X 包围的 O
                if board[i][j] == '#':
                    board[i][j] = 'O'   # (i, j) 一定是能够连接到边缘 O 的 O，所以置回来
        

    def dfs(self, board: List[List[str]], m: int, n: int, i: int, j: int) -> None:
        if i < 0 or i >= m or j < 0 or j >= n:
            return
        if board[i][j] == '#' or board[i][j] == 'X':
            return
        
        board[i][j] = '#'
        self.dfs(board, m, n, i-1, j)    # 上
        self.dfs(board, m, n, i, j+1)    # 右
        self.dfs(board, m, n, i+1, j)    # 下
        self.dfs(board, m, n, i, j-1)    # 左


# 参考题解（强烈推荐）：https://leetcode-cn.com/problems/surrounded-regions/solution/bfsdi-gui-dfsfei-di-gui-dfsbing-cha-ji-by-ac_pipe/
# 和 Soln_1 解法的区别是在：解法一是从 (1,1) ~ (m-2,n-2) 中的 'O' 开始扩散
# 而这个解法是从边缘的 'O' 开始扩散，将从边缘 O 能触及的地方都置成特殊符号#，然后在扫第二遍

