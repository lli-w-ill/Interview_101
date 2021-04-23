#include <vector>
#include <unordered_set>
#include <set>

using std::vector;
using std::unordered_set;
using std::set;

class Solution_2 {
public:
    bool canFinish(int numCourses, vector<vector<int> >& prerequisites) {
        // graph[i]：表示课程i是graph[i]中所有课程的先修课，即在「有向图中」，有从 i -> graph[i]中所有课程编号的有向边
        vector<unordered_set<int> > graph = makeGraph(numCourses, prerequisites);
        // 计算每个节点的「入度 (in degree)」
        vector<int> inDegree = computeInDegree(graph, numCourses);
        // 记录dfs已经访问过的节点，避免某节点被重复访问
        set<int> visited;

        // 开始依次从每个未访问过的节点开始
        while (visited.size() < numCourses) {
            for (int i = 0; i < numCourses; i++) {
                if (visited.find(i) != visited.end()) {
                    // 已经访问过课程号i了
                    continue;
                }
                // 找到第一个当前「入度=0」的节点，因为第一门课一定不能有先修课
                int j;
                for (j = 0; j < numCourses; j++) {
                    if (inDegree[j] == 0) {
                        break;
                    }
                }
                if (j == numCourses) {
                    // 说明：当前所有还未访问过的课程节点都有各自的先修课，所以构成闭环，返回false
                    return false;
                }
                // 到达这里说明找到一门没有先修课的课程j，将该课程的入度设为负值（），并将该课程加入到「已访问节点集中」
                inDegree[j] = -1;
                visited.insert(j);
                // 然后将每个以课程j作为先修课的入度都减1
                for (int neighbor : graph[j]) {
                    inDegree[neighbor] -= 1;
                }
            }
        }
        
        // 打印 graph
        // for (int i = 0; i < graph.size(); i++) {
        //     cout << i << ": ";
        //     for (auto it = graph[i].begin(); it != graph[i].end(); ++it) {
        //         cout << *it << ", ";
        //     }
        //     cout << endl;
        // }
        // cout << "==========" << endl;
        // 打印 inDegree
        // for (int i = 0; i < inDegree.size(); i++) {
        //     cout << i << ": " << inDegree[i] << endl;
        // }
        // cout << endl;
            
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

    vector<int> computeInDegree(vector<unordered_set<int>> &graph, int numCourses) {
        vector<int> inDegree (numCourses, 0);
        for (const unordered_set<int> &neighbors : graph) {
            for (int neighbor : neighbors) {
                inDegree[neighbor] += 1;
            }
        }
        return inDegree;
    }
};


// 参考之前提交的答案
// 思路：首先构造有向图，每次在有向图中的「还未访问过的课程节点」中，寻找一个没有先修课的课程号j，然后将从该课程节点j发出的所有有向边所指向的课程节点，入度减1，直到所有课程节点都已被访问 或者 当前未被访问过的课程中找不到一个入度为0的课程（即这些课程互相依赖，构成一个闭环）

