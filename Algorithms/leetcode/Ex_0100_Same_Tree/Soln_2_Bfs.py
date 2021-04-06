# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution_2:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if p and q:
            return self.bfs(p, q)
        return p == q == None

    def bfs(self, p: TreeNode, q: TreeNode) -> bool:
        parents_p = [p]
        parents_q = [q]
        while parents_p or parents_q:
            children_p = []
            children_q = []
            for cp in parents_p:
                if cp:
                    children_p.append(cp.left)
                    children_p.append(cp.right)
            for cq in parents_q:
                if cq:
                    children_q.append(cq.left)
                    children_q.append(cq.right)
            # 开始逐个对比 parent 的对应值
            if len(parents_p) != len(parents_q):
                return False
            for i in range(len(parents_p)):
                if parents_p[i] == parents_q[i] == None:
                    continue
                elif parents_p[i] is None or parents_q[i] is None:
                    return False
                if parents_p[i].val != parents_q[i].val:
                    return False
            # 开始逐个对比 children 的对应值
            if len(children_p) != len(children_q):
                return False
            for i in range(len(children_p)):
                if children_p[i] == children_q[i] == None:
                    continue
                elif children_p[i] is None or children_q[i] is None:
                    return False
                if children_p[i].val != children_q[i].val:
                    return False
            # parents <- children
            parents_p = children_p
            parents_q = children_q
        return True
