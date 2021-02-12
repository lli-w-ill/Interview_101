# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> TreeNode:
        if not nums:
            return None
        mmax, midx = max((v, i) for (i, v) in enumerate(nums))
        root = TreeNode(mmax)
        # tuple: (parentNode, startIdx, endIdx)
        leftStack, rightStack = [], []
        if midx > 0:
            leftStack.append((root, 0, midx-1))
        if midx < len(nums)-1:
            rightStack.append((root, midx+1, len(nums)-1))
        while leftStack or rightStack:
            while leftStack:
                parent, l, r = leftStack.pop()
                mmax, midx = max((v, i) for (i, v) in enumerate(nums[l:r+1]))
                node = TreeNode(mmax)
                parent.left = node
                if l < midx + l:
                    # 注意偏移量(offset)=l
                    leftStack.append((node, l, midx+l-1))
                if r > midx + l:
                    # 注意偏移量(offset)=l
                    rightStack.append((node, midx+l+1, r))
            while rightStack:
                parent, l, r = rightStack.pop()
                mmax, midx = max((v, i) for (i, v) in enumerate(nums[l:r+1]))
                node = TreeNode(mmax)
                parent.right = node
                if l < midx + l:
                    # 注意偏移量(offset)=l
                    leftStack.append((node, l, midx+l-1))
                if r > midx + l:
                    # 注意偏移量(offset)=l
                    rightStack.append((node, midx+l+1, r))
        return root
