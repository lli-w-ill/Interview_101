import heapq

class Solution_1:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        n = len(matrix)

        # 初始时取第一列作为「最小值候选人列表」
        pq = [(matrix[i][0], i, 0) for i in range(n)]

        # 将 pq 变为一个 heap（默认是最小堆）
        heapq.heapify(pq)

        for i in range(k - 1):  # 先弹出前k-1小的数字
            num, x, y = heapq.heappop(pq)
            if y != n - 1:  # 代表当前 (x, y) 还不是其所在行的最后一个值，那么将其紧挨着的右边的数字也加入堆
                heapq.heappush(pq, (matrix[x][y+1], x, y+1))

        return heapq.heappop(pq)[0]

# 参考题解（非常推荐：https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/solution/shi-yong-dui-heapde-si-lu-xiang-jie-ling-fu-python/
