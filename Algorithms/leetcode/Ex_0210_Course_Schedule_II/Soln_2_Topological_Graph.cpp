#include <vector>
#include <list>
#include <queue>

using std::vector;
using std::list;
using std::queue;

class Graph {
private:
    // 顶点个数
    int numOfVertices;
    // 记录每个顶点的入度
    int *inDegree;
    // 邻接表
    list<int> *adjacencyList;
    // 维护一个入度为 0 的顶点集合
    queue<int> zeroInDegree;

public:
    Graph(int vertices) {
        numOfVertices = vertices;
        adjacencyList = new list<int>[numOfVertices];
        
        inDegree = new int[numOfVertices];
        for (int i = 0; i < numOfVertices; i++) {
            inDegree[i] = 0;
        }
    }

    ~Graph() {
        delete[] adjacencyList;
        delete[] inDegree;
    }

    void addEdge(int source, int destination) {
        adjacencyList[source].push_back(destination);
        inDegree[destination] ++;
    }

    vector<int> getTopologicalOrder() {
        // 将所有入度为 0 的节点加入到队列
        for (int i = 0; i < numOfVertices; i++) {
            if (inDegree[i] == 0) {
                zeroInDegree.push(i);
            }
        }

        vector<int> topologicalOrder;
        while (!zeroInDegree.empty()) {
            // 获得当前第一个入度为 0 的节点
            int vertex = zeroInDegree.front();
            zeroInDegree.pop();

            topologicalOrder.push_back(vertex);

            // 将从 vertex 向外指的其他节点的入度均减 1
            for (list<int>::iterator it = adjacencyList[vertex].begin(); it != adjacencyList[vertex].end(); it++) {
                inDegree[*it] --;
                if (inDegree[*it] == 0) {
                    // 如果减之后入度变为 0，那么加入到队列中
                    zeroInDegree.push(*it);
                }
            }
        }

        // 检查是否还有剩余节点没有访问
        if (topologicalOrder.size() == numOfVertices) {
            return topologicalOrder;
        } else {
            // 存在环，因为有节点没有访问
            return vector<int> {};
        }
    }
};

class Solution_2 {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        Graph graph (numCourses);

        // 添加边
        for (const vector<int> &v : prerequisites) {
            graph.addEdge(v[1], v[0]);
        }

        return graph.getTopologicalOrder();
    }

private:
    
};

// 参考图的拓扑排序实现：https://www.jianshu.com/p/b59db381561a
