# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution_2:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        stack1, stack2 = [root], []
        while stack1:
            node = stack1.pop()
            if not node:
                break
            stack2.append(node.val)
            if node.left:
                stack1.append(node.left)
            if node.right:
                stack1.append(node.right)

        po = []
        while stack2:
            po.append(stack2.pop())
        return po
        # alternative
        # return stack2[::-1]
