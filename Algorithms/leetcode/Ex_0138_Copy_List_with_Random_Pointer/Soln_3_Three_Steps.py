"""
# Definition for a Node.
"""
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random


class Solution_3:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if not head:
            return head

        # 第一步：在原链表中的每个节点后面创建一个自身的拷贝，并连接起来
        # e.g. 1 -> 2 -> 3 -> x  ==>  1 -> 1 -> 2 -> 2 -> 3 -> 3 -> x
        p = head
        while p:
            copy = Node(p.val)
            copy.next = p.next
            p.next = copy
            p = p.next.next     # 或者 p = copy.next
        
        # 第二步：设置新节点的随机节点
        p = head
        while p:
            if p.random:
                # 当前是原节点
                # 注意：在为新节点设置随即节点时，要置为 p.random 的下一个节点，因为p.random.next才是新节点
                p.next.random = p.random.next
            p = p.next.next
        
        # 第三步：将两个链表分离
        p = head
        dummyHead = Node(-1)    # 新链表中的伪头节点
        cur = dummyHead     # 新链表的 itor
        while p:
            cur.next = p.next
            cur = cur.next

            # 分离
            p.next = cur.next

            p = p.next
        
        return dummyHead.next

# 参考题解（非常推荐）：https://leetcode-cn.com/problems/copy-list-with-random-pointer/solution/liang-chong-shi-xian-tu-jie-138-fu-zhi-dai-sui-ji-/

