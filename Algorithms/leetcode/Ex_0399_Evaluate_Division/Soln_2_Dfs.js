/**
 * @param {string[][]} equations
 * @param {number[]} values
 * @param {string[][]} queries
 * @return {number[]}
 */
var calcEquation = function(equations, values, queries) {
    // 邻接表 (adjacency list)
    // key: str (start node)
    // value: List of List, where in each inner list, li[0] is the next node, li[1] is 商
    let adjList = new Map();
    // 初始化邻接表
    for (let i = 0; i < equations.length; i++) {
        let e = equations[i];
        let val = values[i];

        if (!adjList.has(e[0])) {
            // 第一次访问节点e[0]
            adjList.set(e[0], []);
        }
        if (!adjList.has(e[1])) {
            // 第一次访问节点e[1]
            adjList.set(e[1], []);
        }

        // 加入边 e[0] --> e[1] 到邻接表
        adjList.get(e[0]).push([e[1], val]);
        // 加入边 e[1] --> e[0] 到邻接表
        adjList.get(e[1]).push([e[0], 1 / val]);
    }
    // console.log(adjList);

    // 定义 dfs 函数
    const dfs = (src, dst) => {
        // 源节点就是目标节点，src/dst = 1
        if (src == dst) {
            return 1.0;
        }

        // 得到从 src 出去的所有边
        let edges = adjList.get(src);

        // 遍历 src 所有的边，若未访问过，则访问
        if (edges != undefined && edges.length > 0) {
            for (let edge of edges) {
                // edge[0]: next node
                // edge[1]: edge weight，即 src / edge[0] 的商
                if (!visited.has(edge[0])) {
                    visited.add(edge[0]);
                    let result = dfs(edge[0], dst); // edge[0] / dst 的商
                    visited.delete(edge[0]);    // 回溯

                    if (result != -1.0) {
                        // edge[0] -> dst 可达, edge[0] / dst = result
                        // 那么 src / dst = (src / edge[0]) * (edge[0] / dst) = edge[1] * result
                        return edge[1] * result;
                    }
                } 
            }
        }
        // 已尝试了所有边，都不可达
        return -1.0;
    }

    let res = [];
    let visited = new Set();
    // 计算每个公式
    for (let q of queries) {
        let node1 = q[0];
        let node2 = q[1];

        if (adjList.has(node1) && adjList.has(node2)) {
            // 如果能计算 node1 -> node2 是否可达，必须提供的公式里有这两个节点
            visited.add(node1);
            res.push(dfs(node1, node2));
            visited.delete(node1);  // 回溯
        } else {
            res.push(-1.0);
        }
    }

    return res;
};

// 参考题解（非常推荐）：https://leetcode-cn.com/problems/evaluate-division/solution/js-lin-jie-biao-dfs-by-yleave-l8p5/
// 思路：a->b的边权表示 a/b 的商，这样的好处是 a-(x)->b ==> a/b = x, b-(y)->c ==> b/c = y, 那么 a/c == a/b * b/c = x * y
