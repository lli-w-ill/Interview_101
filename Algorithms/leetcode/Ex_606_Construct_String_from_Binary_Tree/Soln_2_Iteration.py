# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def tree2str(self, t: TreeNode) -> str:
        if not t:
            return ''
        stack = [t]
        visited = set()
        s = ''
        while stack:
            # 这里不要直接pop，因为要等到访问完左右子树后回来时加上最后的右括号（除了root节点和没加入stack的叶子结点）
            node = stack[-1]
            if node not in visited:
                visited.add(node)
                s += '(' + str(node.val)
                if not node.left and not node.right:
                    # 叶子结点：没有左右子树
                    # 不需要加上()()
                    s += ''
                if not node.left and node.right:
                    s += '()'
                # 注意这里如果有右孩子，先把右孩子加入，再把左孩子加入（“为什么”见105题迭代解法）
                if node.right:
                    stack.append(node.right)
                if node.left:
                    stack.append(node.left)
            else:
                s += ')'
                _ = stack.pop()
        return s[1:-1]


# 参考：https://leetcode-cn.com/problems/construct-string-from-binary-tree/solution/gen-ju-er-cha-shu-chuang-jian-zi-fu-chuan-by-leetc/
# 需要借助一个visited集合来辅助
