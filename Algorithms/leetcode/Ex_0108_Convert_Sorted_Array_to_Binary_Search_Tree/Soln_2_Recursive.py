# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution_2:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        return self.sortedArrayRangeToBST(nums, 0, len(nums))
    
    # nums[start, end)
    # 左边界包括，右边界不包括
    def sortedArrayRangeToBST(self, nums: List[int], start: int, end: int) -> TreeNode:
        if start == end:
            return None
        
        mid = (start + end) >> 1
        cur = TreeNode(nums[mid])
        cur.left = self.sortedArrayRangeToBST(nums, start, mid)
        cur.right = self.sortedArrayRangeToBST(nums, mid+1, end)
        return cur


# 参考题解（非常推荐）：https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-24/
# 另外：python 不支持 function overloading：https://stackoverflow.com/questions/6434482/python-function-overloading
