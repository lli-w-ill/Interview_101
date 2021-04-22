# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

from collections import Counter

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if not head or not head.next:
           return head
        
        # 创建一个伪节点，保持头节点不变，因为head也可能是重复节点
        dummy = ListNode(-1, head)

        # 将链表中所有的值存在一个 list 中
        val_list = []
        while head:
            val_list.append(head.val)
            head = head.next
        
        # 统计每个数字的计数
        counter = Counter(val_list)
        
        head = dummy
        while head and head.next:
            if counter[head.next.val] != 1:
                # head.next 节点不止出现了一次，跳过
                head.next = head.next.next
            else:
                # head.next 节点只出现了一次
                head = head.next
        
        return dummy.next
        

# 参考题解（非常推荐）：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/solution/fu-xue-ming-zhu-di-gui-die-dai-yi-pian-t-wy0h/

