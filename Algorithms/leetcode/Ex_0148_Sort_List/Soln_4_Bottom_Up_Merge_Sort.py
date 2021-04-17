# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution_4:
    def sortList(self, head: ListNode) -> ListNode:
        h = head
        length = 0  # 表示原链表长度
        intv = 1    # 表示合并操作时，每一段链表的长度（由于原链表长度可能不恰好是2^n，最后一段有可能长度<=intv）
        # 计算原链表长度
        while h:
            h = h.next
            length += 1
        # 定义伪头节点，用来存储合并排序链表后的「结果链」
        res = ListNode(0)
        res.next = head # 将伪头节点与原链表相连
        # 逐渐递增每个合并单元的长度intv，直到每个合并单元长度intv >= length
        while intv < length:
            prev = res      # prev 表示上一个合并排序后的「结果链」的尾节点，也就是head一直到prev（包括prev）都是排好序的（prev初始为伪头节点res）
            h = res.next    # h 表示接下来需要两两合并的开始位置
            # 两两合并长度为intv的链表单元
            while h:
                # 得到两两合并的链表单元的头节点(h1, h2)
                h1 = h  # 要合并的第一个链表单元
                i = intv
                while i > 0 and h is not None:  # 这里h is not None为了考虑单个链表单元长度 < intv 的情况
                    h = h.next
                    i -= 1
                # 检查是否上面while循环是因为 h is not None 退出的
                if i > 0:
                    # 说明是，已经到达最后一个链表单元，且该单元长度小于 intv，没有必要再合并了，因为没有和它配对的「第二个单元」
                    break
                len1 = intv    # h1 单元的链表长度

                h2 = h  # 要合并的第二个链表单元
                i = intv    # 重置，往后走intv步
                while i > 0 and h is not None:  # 这里h is not None理由同上 
                    h = h.next
                    i -= 1
                len2 = intv - i    # h2 单元的链表长度（第二条链长度可能 <= intv，由于原链表长度可能不恰好是 2^n）
                # 好了，现在两个单元的头部都拿到了，需要合并 h1 和 h2 了 （注意：这里要合并的两个单元 h1, h2 其实是连着的，与递归版归并排序需要把两个「半条链」切开不同，这里 h1 的尾部连接着 h2）
                # 合并循环
                while len1 > 0 and len2 > 0:
                    if h1.val < h2.val:
                        # 上面已经定了prev代表上一个两两合并链表单元后的尾部
                        prev.next = h1
                        h1 = h1.next    # 向前推进 h1
                        len1 -= 1     # 收缩第一个链表单元 h1
                    else:
                        prev.next = h2
                        h2 = h2.next
                        len2 -= 1
                    # 向前推进尾部指针
                    prev = prev.next 
                # 将还遍历完的链表单元的头部 接在 prev 后面
                if len1 > 0:
                    prev.next = h1
                elif len2 > 0:
                    prev.next = h2
                # 每次结束前，需要将 prev 再向前推进到当前两两合并后的尾部
                if len1 > 0:
                    # 说明上面的 while 循环遍历完了 h2，没有遍历完 h1，所以再需要吧 prev 向前推进 h1 还没遍历完的长度
                    while len1 > 0:
                        prev = prev.next
                        len1 -= 1
                elif len2 > 0:
                    # 说明上面的 while 循环遍历完了 h1，没有遍历完 h2，所以再需要吧 prev 向前推进 h2 还没遍历完的长度
                    while len2 > 0:
                        prev = prev.next;
                        len2 -= 1
                prev.next = h
            intv *= 2
        return res.next

# 参考题解：https://leetcode-cn.com/problems/sort-list/solution/sort-list-gui-bing-pai-xu-lian-biao-by-jyd/
# 时间复杂度：O(nlogn)
# 空间复杂度：O(1)
