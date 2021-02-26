package Algorithms.leetcode.Ex_279_Perfect_Squares;

import java.util.Queue;
import java.util.LinkedList;
import java.util.HashSet;
import java.util.ArrayList;

class Node {
    public int residual;
    public int step;

    public Node(int resi, int st) {
        residual = resi;
        step = st;
    }
}

class Solution_4 {
    public int numSquares(int n) {
        Queue<Node> queue = new LinkedList<Node>();
        HashSet<Integer> visited = new HashSet<Integer>();
        queue.add(new Node(n, 0));
        // 开始 bfs 循环
        while (!queue.isEmpty()) {
            // 移除并获得当前头节点
            Node node = queue.poll();

            // 保存当前node的剩余量(node.residual) 依次减去所有能减去的完全平方数 后的结果
            ArrayList<Integer> residuals = new ArrayList<Integer>();
            for (int i = 1; i <= Math.floor(Math.sqrt(node.residual)); i++) {
                residuals.add(node.residual - i * i);
            }

            // 依次将新的node加入到queue中
            for (int resi : residuals) {
                if (resi == 0) {
                    // 找到结果了
                    return node.step + 1;
                }
                // hashset方式重复计算之前加入过queue的node
                if (!visited.contains(resi)) {
                    Node newNode = new Node(resi, node.step + 1);
                    queue.add(newNode);
                    visited.add(resi);
                }
            }
        }
        return -1;
    }
}

// 参考题解：https://leetcode-cn.com/problems/perfect-squares/solution/python3zui-ji-chu-de-bfstao-lu-dai-ma-gua-he-ru-me/

