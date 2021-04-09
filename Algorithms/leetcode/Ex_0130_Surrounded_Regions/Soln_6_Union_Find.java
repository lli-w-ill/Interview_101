package Algorithms.leetcode.Ex_0130_Surrounded_Regions;

class UnionFind {
    int[] parents;

    public UnionFind(int totalNodes) {
        parents = new int[totalNodes];
        // 初始时，每个节点的根结点就是他们自己
        for (int i = 0; i < totalNodes; i++) {
            parents[i] = i;
        }
    }

    // 合并 node1, node2 两个点所在的连通区域
    // 合并连通区域是通过 find 来操作的，即看这两个节点是不是在同一个连通区域内
    void union(int node1, int node2) {
        // 查找 node1 的根结点
        int root1 = find(node1);
        // 查找 node2 的根结点
        int root2 = find(node2);
        // 检查这两个节点是不是在同一个连通区域内（即有相同的root）
        if (root1 != root2) {
            parents[root2] = root1;
        }
    }

    // 查找 node 点的根结点
    int find(int node) {
        while (parents[node] != node) {
            // 当前节点的父节点指向父节点的父节点
            // 保证一个连通区域最终的 parents 只有一个
            parents[node] = parents[parents[node]];
            node = parents[node];
        }

        // 只有根结点的父节点是他自己
        return node;
    }

    // 判断 node1, node2 两个点是否在一个连通区域
    boolean isConnected(int node1, int node2) {
        return find(node1) == find(node2);
    }
}

class Solution_6 {
    private int rows;
    private int cols; 

    public void solve(char[][] board) {
        if (board == null || board.length == 0) {
            return;
        }

        rows = board.length;
        cols = board[0].length;

        // 虚节点，边界上的 O 的父节点都置为这个虚节点
        UnionFind uf = new UnionFind(rows * cols + 1);
        int dummyNode = rows * cols;

        // 扫描第一遍
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O') {
                    // 如果遇到的是边界上的 O，则与虚节点合并成一个连通区域
                    boolean isEdge = (i == 0 || j == 0 || i == rows - 1 || j == cols - 1);
                    if (isEdge) {
                        uf.union(node(i, j), dummyNode);
                    }
                    // 如果不是边界上的 O，则与其四个方向上的 O 进行合并
                    else {
                        if (i - 1 >= 0 && board[i-1][j] == 'O') {
                            uf.union(node(i, j), node(i-1, j));
                        }
                        if (i + 1 < rows && board[i+1][j] == 'O') {
                            uf.union(node(i, j), node(i+1, j));
                        }
                        if (j - 1 >= 0 && board[i][j-1] == 'O') {
                            uf.union(node(i, j), node(i, j-1));
                        }
                        if (j + 1 < cols && board[i][j+1] == 'O') {
                            uf.union(node(i, j), node(i, j+1));
                        }
                    }
                }
            }
        }

        // 扫描第二遍
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (uf.isConnected(node(i, j), dummyNode)) {
                    // 与虚节点相连
                    board[i][j] = 'O';  // 这句话其实可以注释掉，因为board前后都没有变
                } else {
                    // 被 X 包围的 O
                    board[i][j] = 'X';
                }
            }
        }
    }

    // 将二维坐标转为一维下标
    private int node(int i, int j) {
        return i * cols + j;
    }
}

// 参考题解（强烈推荐）：https://leetcode-cn.com/problems/surrounded-regions/solution/bfsdi-gui-dfsfei-di-gui-dfsbing-cha-ji-by-ac_pipe/

