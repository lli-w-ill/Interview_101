# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import defaultdict


class Solution:
    def findDuplicateSubtrees(self, root: TreeNode) -> List[TreeNode]:
        if not root:
            return []
        dic = defaultdict(list)  # key: val; value: 以key为值的所有node
        self.iterativeDfs(root, dic)
        ans = []
        for val in dic.keys():
            if len(dic[val]) >= 2:
                for i in range(len(dic[val])):
                    for j in range(i+1, len(dic[val])):
                        if self.sameTree(dic[val][i], dic[val][j]):
                            ans.append(dic[val][i])
                            break
        # 筛出ans中重复的子树
        repeatIdx = set()
        for i in range(len(ans)):
            for j in range(i+1, len(ans)):
                if self.sameTree(ans[i], ans[j]):
                    repeatIdx.add(j)
        return [ans[i] for i in range(len(ans)) if i not in repeatIdx]

    def iterativeDfs(self, root: TreeNode, dic: Dict[int, List[TreeNode]]) -> None:
        stack = [root]
        while stack:
            node = stack.pop()
            if node.right:
                stack.append(node.right)
            if node.left:
                stack.append(node.left)
            dic[node.val].append(node)

    def sameTree(self, root1: TreeNode, root2: TreeNode) -> bool:
        if root1 and root2:
            return (root1.val == root2.val) and self.sameTree(root1.left, root2.left) and self.sameTree(root1.right, root2.right)
        if root1 or root2:
            return False
        return True

# 该解法参考Ex100: Same Tree的解法
