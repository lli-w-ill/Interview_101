# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution_1:
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        nums = []
        while head:
            nums.append(head.val)
            head = head.next
        return self.ex108(nums)

    def ex108(self, nums: List[int]) -> TreeNode:
        if not nums:
            return None
        mid = len(nums) // 2
        root = TreeNode(nums[mid])
        root.left, root.right = self.ex108(nums[:mid]), self.ex108(nums[mid+1:])
        return root

# 建议和 Ex.108 一起做
# 方法一：直接用 Ex.108 的实现，将链表中的值放在一个数组中

