# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution_3:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        # base case
        if not head or not head.next:
            return head
        
        if head.val != head.next.val:
            head.next = self.deleteDuplicates(head.next)
        else:
            # 往后找到和 head.val 不同的第一个节点
            move = head.next
            while move and head.val == move.val:
                move = move.next
            return self.deleteDuplicates(move)
            
        return head

# 参考题解（非常推荐）：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/solution/fu-xue-ming-zhu-di-gui-die-dai-yi-pian-t-wy0h/
