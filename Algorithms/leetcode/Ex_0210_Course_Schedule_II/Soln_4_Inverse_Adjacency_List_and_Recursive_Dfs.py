class Solution_4:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        length = len(prerequisites)

        if length == 0:
            return [i for i in range(numCourses)]
        
        # 创建逆邻接表
        # 下标作为课程号
        # 实际值作为指向当前课程的课程号列表
        inverseAdjacencyList = [set() for _ in range(numCourses)]
        for destination, source in prerequisites:
            inverseAdjacencyList[destination].add(source)
        
        # 记录每个节点当前的访问状态（相当于 Soln_1 中的 color）
        # 0: 还没访问
        # 1: 已经访问完该节点的所有前去节点
        # 2: 正在访问
        visited = [0 for _ in range(numCourses)]

        res = []
        for i in range(numCourses):
            if self.dfs(i, inverseAdjacencyList, visited, res):
                return []
        return res

    # 如果有环返回 True，没有环返回 False
    def dfs(self, courseNo: int, inverseAdjacencyList: List[Set[int]], visited: List[int], res: List[int]) -> bool:
        if visited[courseNo] == 2:
            return True
        elif visited[courseNo] == 1:
            return False
        
        visited[courseNo] = 2   # 标记为正在访问
        
        # 递归访问 courseNo 的所有前驱节点
        for precursor in inverseAdjacencyList[courseNo]:
            if self.dfs(precursor, inverseAdjacencyList, visited, res):
                # 如果中途检查到有环，返回 True
                return True
        
        # 能走到这里，说明当前课程 courseNo 的所有前驱节点都访问过了，更新状态并将当前课程加入到结果列表中
        visited[courseNo] = 1
        res.append(courseNo)

        return False    # 没有环


# 参考题解（强烈推荐）：https://leetcode-cn.com/problems/course-schedule-ii/solution/tuo-bu-pai-xu-shen-du-you-xian-bian-li-python-dai-/
# 这个解法使用的是「逆邻接表」
# 来自百科：
# 逆邻接表：任一表头结点下的边结点的数量是图中该结点入度的弧的数量，与邻接表相反。图的邻接表，反映的是节点的出度邻接情况，图的逆邻接表反映的是节点的入度邻接情况。
