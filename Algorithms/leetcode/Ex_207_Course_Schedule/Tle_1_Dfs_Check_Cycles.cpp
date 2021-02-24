#include <vector>
#include <unordered_set>

using std::vector;
using std::unordered_set;

class Tle_1 {
public:
    bool canFinish(int numCourses, vector<vector<int> >& prerequisites) {
        // graph[i]：表示课程i是graph[i]中所有课程的先修课，即在「有向图中」，有从 i -> graph[i]中所有课程编号的有向边
        vector<unordered_set<int> > graph = makeGraph(numCourses, prerequisites);
        // 记录当前dfs访问路径上的所有节点
        vector<bool> onPathNodes(numCourses, false);
        // 记录当前dfs访问过的所有节点
        vector<bool> visited(numCourses, false);

        // 开始依次从每个未访问过的节点开始 run 一遍 dfs 循环
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && dfsCheckCycle(graph, i, onPathNodes, visited)) {
                return false;
            }
        }
        return true;
    }

private:
    vector<unordered_set<int> > makeGraph(int numCourses, vector<vector<int> >& prerequisites) {
        vector<unordered_set<int> > graph(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            vector<int> edge = prerequisites[i];
            // edge[0]: 要学习的课程 a
            // edge[1]: 课程 a 的先修课
            graph[edge[1]].insert(edge[0]);
        }
        return graph;
    }

    bool dfsCheckCycle(const vector<unordered_set<int> > &graph, int courseNumber, vector<bool> &onPathNodes, vector<bool> &visited) {
        if (onPathNodes[courseNumber]) {
            // 说明 courseNumber 已经在「当前的dfs访问路径上」，即检查到cycle
            return false;
        }
        // 将当前课号加入到「dfs访问路径上的节点集」 和 「dfs访问过的节点集」中
        onPathNodes[courseNumber] = true;
        visited[courseNumber] = true;
        // 开始从 courseNumber 继续向它指向的课程访问
        for (int nextCourseNumber : graph[courseNumber]) {
            if (onPathNodes[nextCourseNumber] || dfsCheckCycle(graph, nextCourseNumber, onPathNodes, visited)) {
                return true;
            }
        }
        // 恢复状态，因为当从当前 courseNumber 后面的课程检查完 cycle 后，要从当前 courseNumber 退回来，所以要将 courseNumber 从「当前dfs路径上的节点集」中移除
        onPathNodes[courseNumber] = false;
        return false;
    }
};


// 参考之前提交的答案
// 思路：首先思考如何表达 Graph，由题目可知所有课程和其先修课一定能够有一张「有向图」来表达。这里如果课程 a 的先修课是课程 b，则在图中画一个由 b -> a 的边
// 步骤1: 首先建立 Graph 的表达形式，这里使用的是临界数组，即下标表示课程 b，它是它后面接的set中所有课程的先修课
// 例如：    index    pre-requisite (set)
//            0             1
//            1             -
//            2             0
// 可表示如下有向图:
//      0 ------> 2
//      ^
//      |
//      1  
// 步骤2: 定义两个数组来用于当前dfs遍历中的路径，和访问过的节点
// 步骤3: 从每个点还未被 dfs 访问过的节点开始 run dfs，检查cycle


