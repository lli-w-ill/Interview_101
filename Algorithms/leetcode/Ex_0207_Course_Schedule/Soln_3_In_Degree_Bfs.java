package Algorithms.leetcode.Ex_0207_Course_Schedule;

import java.util.List;
import java.util.ArrayList;
import java.util.Deque;
import java.util.ArrayDeque;

class Solution_3 {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        // 首先初始化邻接表和入度表
        int[] inDegrees = new int[numCourses];
        List<List<Integer>> adjacencyList = new ArrayList<List<Integer>>();
        for (int i = 0; i < numCourses; i++) {
            adjacencyList.add(new ArrayList<Integer>());
            inDegrees[i] = 0;
        }
        // 构建邻接表，并计算每个节点的入度
        for (int[] edge : prerequisites) {
            // edge[0] : 课程 a
            // edge[1] : 课程 b，且是a的先修课，所以在有向图中，应该话题一条 b --> a 的边
            adjacencyList.get(edge[1]).add(edge[0]);
            inDegrees[edge[0]] += 1;
        }
        // 首先将所有入度为0的节点入队
        Deque<Integer> queue = new ArrayDeque<Integer>();
        for (int i = 0; i < numCourses; i++) {
            if (inDegrees[i] == 0) {
                queue.addLast(i);
            }
        }
        // 只要queue不为空，则依次出队首节点pre，并移除从pre发出的所有边，并对pre连接到node的入度减1
        // 当减完入度后，如果更新后的入度为0，则将其加入到queue中，可作为新的起始节点
        while (!queue.isEmpty()) {
            int startCourseNumber = queue.pollFirst();
            // 首先删除该节点，根据题解，这里是“伪删除”（设其入度设为-1）
            inDegrees[startCourseNumber] = -1;
            // 将此节点对应所有邻接节点 cur 的入度 -1
            for (int connectedCourseNumber : adjacencyList.get(startCourseNumber)) {
                inDegrees[connectedCourseNumber] -= 1;
                if (inDegrees[connectedCourseNumber] == 0) {
                    queue.addLast(connectedCourseNumber);
                }
            }
            numCourses -= 1;
        }
        // 如果当queue为空时，有向图中的节点全部入过队，且依次出队，那么numCourses=0
        // 如果当queue为空时，有向图中存在一个有向环，则numCourses>0
        return numCourses == 0;
    }
}

// 参考题解（非常推荐）：https://leetcode-cn.com/problems/course-schedule/solution/course-schedule-tuo-bu-pai-xu-bfsdfsliang-chong-fa/
// 思路：通过「拓扑排序」判断有向图中是否是「有向无环图」(DAG, Directed Acyclic Graph)
// 时间复杂度：O(N + M)  (N: Number of nodes/courses)
// 空间复杂度：O(N + M)  (M: Number of edges/pre-requisite relations)
