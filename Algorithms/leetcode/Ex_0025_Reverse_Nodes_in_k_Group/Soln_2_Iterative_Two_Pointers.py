# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution_2:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        # 新建一个伪头节点
        dummy = ListNode(-1)
        dummy.next = head

        pre = dummy     # 前驱节点（上一组的最后一个节点）
        end = dummy     # 后继节点（当前组翻转前的最后一个节点，即翻转后的头节点）

        while end.next:
            # 先找到后继节点
            for i in range(k):
                end = end.next
                if end is None:
                    break
            if end is None:
                # 当前组不够 k 个节点，直接退出循环
                break

            start = pre.next    # 当前组（翻转前）的头节点
            next = end.next     # 下一组（翻转前）的头节点
            end.next = None     # 断开当前组（翻转前）的尾节点 和 下一组头节点的联系（这里是为了 reverse 函数中的翻转做准备）

            # 翻转链表 start ... 一直到结尾（因为上面已经断开了和下一组的联系），并将前驱节点和翻转后的头节点连接起来
            pre.next = self.reverse(start)

            # start 作为翻转前的头节点，也是翻转后为尾节点，连接下一组翻转前的头节点（这样如果下一组不满 k 个，不用加额外判断，如果满 k 个节点会通过上一句的 pre 覆盖改写）
            start.next = next

            # 更新前驱节点（用于覆盖改写当前组翻转后的尾节点和下一组翻转后的头节点，当然是当如果下一组满 k 个节点的话）
            pre = start

            # 更新后继节点，设置为当前组翻转后的尾节点，用于为下一组寻找新的尾节点
            end = start

        return dummy.next
    
    # 翻转 head 和之后的节点（一直到.next为空），可以这么做因为我们在 reverseKGroup 中断开了当前组和下一组的连接，而head指向的是当前组的头节点；最终这个函数应当返回翻转后的头节点
    def reverse(self, head: ListNode) -> ListNode:
        pre = None
        cur = head
        while cur:
            next = cur.next     # 记录下一个节点
            # 翻转 pre, cur 为 pre <- cur
            cur.next = pre
            # 更新 pre, cur
            pre = cur
            cur = next
        return pre


# 参考题解（非常推荐）：https://leetcode-cn.com/problems/reverse-nodes-in-k-group/solution/tu-jie-kge-yi-zu-fan-zhuan-lian-biao-by-user7208t/
# 设原链表长度为 N
# Time Complexity: O(N * k)
# Space Complexity: O(1)
