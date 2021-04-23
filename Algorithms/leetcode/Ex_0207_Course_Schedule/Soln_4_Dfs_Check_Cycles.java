package Algorithms.leetcode.Ex_0207_Course_Schedule;

import java.util.List;
import java.util.ArrayList;

class Solution_4 {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        // 和其他方法一样，首先初始化邻接表
        List<List<Integer>> adjacencyList = new ArrayList<List<Integer>>();
        // 记录每个节点的当前状态
        //      status[i] = 0  -->  课程节点i还未被dfs访问
        //      status[i] = 1  -->  课程节点i在当前的dfs访问路径上，即「正在被访问」
        //      status[i] = -1 -->  课程节点i已被dfs访问过，且已检验过i的所有后续节点，即「已从i退回来过」
        int[] status = new int[numCourses];
        for (int i = 0; i < numCourses; i++) {
            adjacencyList.add(new ArrayList<Integer>());
            status[i] = 0;
        }
        // 构建邻接表
        for (int[] edge : prerequisites) {
            // edge[0] : 课程 a
            // edge[1] : 课程 b，且是a的先修课，所以在有向图中，有一条 b --> a 的边
            adjacencyList.get(edge[1]).add(edge[0]);
        }

        // 从每个课程节点开始dfs遍历
        for (int startCourseNumber = 0; startCourseNumber < numCourses; startCourseNumber++) {
            if (dfsCheckHasCycle(adjacencyList, status, startCourseNumber)) {
                return false;
            }
        }
        return true;
    }

    private boolean dfsCheckHasCycle(List<List<Integer>> adjacencyList, int[] status, int courseNumber) {
        if (status[courseNumber] == -1) {
            // 说明已经检查过courseNumber
            return false;
        }
        if (status[courseNumber] == 1) {
            // 说明courseNumber当前正在dfs路径上，也就是说我们第二次访问了courseNumber节点，所以一定有环
            return true;
        }
        // 修改当前课程节点的状态为「正在检查中」
        status[courseNumber] = 1;
        // 访问其所有邻接节点
        for (Integer connectedCourseNumber : adjacencyList.get(courseNumber)) {
            if (dfsCheckHasCycle(adjacencyList, status, connectedCourseNumber)) {
                return true;
            }
        }
        // 修改当前课程节点的状态为「已经检查过，无环」
        status[courseNumber] = -1;
        return false;
    }
}

// 参考题解（非常推荐）：https://leetcode-cn.com/problems/course-schedule/solution/course-schedule-tuo-bu-pai-xu-bfsdfsliang-chong-fa/

