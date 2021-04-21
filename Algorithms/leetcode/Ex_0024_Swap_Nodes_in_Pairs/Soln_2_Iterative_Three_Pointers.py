# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution_2:
    def swapPairs(self, head: ListNode) -> ListNode:
        if head is None:
            return head
        
        p1 = head
        p2 = p1.next
        if p2 is not None:
            p3 = p2.next
        else:
            p3 = None
        
        # 更新头节点
        if p2 is not None:
            head = p2

        # 以下注释以 1 -> 2 -> 3 -> 4 -> 5 为例子
        while p1 and p2:
            if p3 is None:
                # 连接 3 -> 5 in 2 -> 1 -> 4 -> 3 -> 5
                p1.next, p2.next = p3, p1
            elif p3.next is not None:
                # 连接 1 -> 4 in 2 -> 1 -> 4 -> 3 -> 5
                p1.next, p2.next = p3.next, p1
            else:
                p1.next, p2.next = p2.next, p1
            
            # 更新p1, p2, p3
            p1 = p3
            if p1 is not None:
                p2 = p1.next
                if p2 is not None:
                    p3 = p2.next
        
        return head

# 参考之前账号提交记录
