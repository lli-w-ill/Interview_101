# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None, next=None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next


class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        head = self.connect(root)
        currLevelLeftmost = head
        rightView = []
        while currLevelLeftmost:
            currLevelRightmost = currLevelLeftmost
            while getattr(currLevelRightmost, 'next', None):
                currLevelRightmost = currLevelRightmost.next
            rightView.append(currLevelRightmost.val)
            currLevelLeftmost = currLevelLeftmost.left
        return rightView[:-1]

    def connect(self, root: TreeNode) -> TreeNode:
        currParent = root
        dummy = TreeNode(0)
        dummy.next = root
        head = dummy
        while currParent:
            newDummy = TreeNode(0)
            dummy.left = newDummy
            dummy = newDummy
            prev = dummy
            while currParent:
                if currParent.left:
                    prev.next = currParent.left
                    prev = prev.next
                if currParent.right:
                    prev.next = currParent.right
                    prev = prev.next
                currParent = getattr(currParent, 'next', None)
            # update currParent to the first node in the current level
            currParent = dummy.next
        return head

# 注：借用117题的思路
