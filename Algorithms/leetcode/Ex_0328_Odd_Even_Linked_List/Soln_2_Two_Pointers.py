# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution_2:
    def oddEvenList(self, head: ListNode) -> ListNode:
        if not head:
            return head
        oddHead = odd = head
        evenHead = even = head.next

        while odd.next and even.next:
            odd.next = odd.next.next
            even.next = even.next.next
            odd, even = odd.next, even.next
        
        # 连接奇偶链表
        odd.next = evenHead
        
        return oddHead

# 参考题解：https://leetcode-cn.com/problems/odd-even-linked-list/solution/zui-po-su-de-xiang-fa-dai-ma-zhu-shi-fei-chang-xia/
