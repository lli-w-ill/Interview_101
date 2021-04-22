# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution_4:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if not head or not head.next:
           return head
        
        # 创建一个伪节点，保持头节点不变，因为head也可能是重复节点
        dummy = ListNode(-1, head)
        pre = dummy
        cur = head

        while cur:
            while cur.next and cur.val == cur.next.val:
                cur = cur.next
            if pre.next == cur:
                # cur 是 pre 紧接着的下一个节点，所以 pre 和 cur 之间（不包括二者）没有重复节点
                pre = pre.next
            else:
                # 让 pre.next 指向 cur.next
                # 因为当前 cur 是其所在重复序列的最后一个节点
                pre.next = cur.next
            cur = cur.next
        
        return dummy.next

# 参考题解（非常推荐）：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/solution/fu-xue-ming-zhu-di-gui-die-dai-yi-pian-t-wy0h/

