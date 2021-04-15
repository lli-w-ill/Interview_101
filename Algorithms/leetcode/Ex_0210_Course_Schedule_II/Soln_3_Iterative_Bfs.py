class Solution_3:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        length = len(prerequisites)

        if length == 0:
            # 没有前置要求，可以按照顺序修
            return [i for i in range(numCourses)]
        
        # 入度数组 和 邻接表 都用下标作为课程号
        inDegree = [0 for _ in range(numCourses)]
        adjacencyList = [set() for _ in range(numCourses)]

        # 建图
        for destination, source in prerequisites:
            inDegree[destination] += 1
            adjacencyList[source].add(destination)
        
        visited = []
        zeroDegreeQueue = []    # 每一轮需要维护入度为 0 的所有节点
        
        # 首先把所有初始入度为 0 的课程加入
        for i in range(numCourses):
            if inDegree[i] == 0:
                zeroDegreeQueue.append(i)
        
        # 开始 bfs
        while zeroDegreeQueue:
            front = zeroDegreeQueue.pop(0)
            visited.append(front)

            # front 指向的所有课程入度 -1
            for successor in adjacencyList[front]:
                inDegree[successor] -= 1
                # 维护 零入度队列
                if inDegree[successor] == 0:
                    zeroDegreeQueue.append(successor)
        
        # 检查访问过的节点数是否等于所有课程数
        return visited if len(visited) == numCourses else []


# 参考题解（强烈推荐）：https://leetcode-cn.com/problems/course-schedule-ii/solution/tuo-bu-pai-xu-shen-du-you-xian-bian-li-python-dai-/
