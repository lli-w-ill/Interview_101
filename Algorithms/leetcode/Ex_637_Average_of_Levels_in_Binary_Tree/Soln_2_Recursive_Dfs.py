# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        if not root:
            return []
        avg, cnt = [], []
        self.dfs(root, 1, avg, cnt)
        return [avg[i] / cnt[i] for i in range(len(avg))]

    def dfs(self, node: TreeNode, depth: int, avg: List[int], cnt: List[int]) -> None:
        if depth > len(avg):
            # 第一次到depth层
            avg.append(0)
            cnt.append(0)
        avg[depth-1] += node.val    # depth-1作为index
        cnt[depth-1] += 1
        if node.left:
            self.dfs(node.left, depth+1, avg, cnt)
        if node.right:
            self.dfs(node.right, depth+1, avg, cnt)
