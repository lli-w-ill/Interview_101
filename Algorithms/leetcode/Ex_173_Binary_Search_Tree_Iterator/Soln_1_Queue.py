# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:

    def __init__(self, root: TreeNode):
        self.queue = []
        while root:
            self.queue.append(root)
            root = root.left

    def next(self) -> int:
        smallest = self.queue.pop()
        # add left children in smallest's right subtree
        temp = smallest.right
        while temp:
            self.queue.append(temp)
            temp = temp.left
        return smallest.val

    def hasNext(self) -> bool:
        return len(self.queue) > 0


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()


# 时间复杂度O(1)解释参考：https://leetcode-cn.com/problems/binary-search-tree-iterator/solution/nextshi-jian-fu-za-du-wei-o1-by-user5707f/
