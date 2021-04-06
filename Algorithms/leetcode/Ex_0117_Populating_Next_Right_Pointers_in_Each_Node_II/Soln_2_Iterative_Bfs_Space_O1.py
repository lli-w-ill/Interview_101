"""
# Definition for a Node.
"""
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next


from collections import defaultdict


class Solution_2:
    def connect(self, root: 'Node') -> 'Node':
        currParent = root
        dummy = Node(0)
        while currParent:
            prev = dummy
            while currParent:
                if currParent.left:
                    prev.next = currParent.left
                    prev = prev.next
                if currParent.right:
                    prev.next = currParent.right
                    prev = prev.next
                currParent = currParent.next
            # update currParent to the first node in the current level
            currParent = dummy.next
            dummy.next = None
        return root

# 参考：https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/solution/bfsjie-jue-zui-hao-de-ji-bai-liao-100de-yong-hu-by/
