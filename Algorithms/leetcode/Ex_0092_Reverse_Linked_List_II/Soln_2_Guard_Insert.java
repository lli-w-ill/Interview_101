package Algorithms.leetcode.Ex_0092_Reverse_Linked_List_II;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution_2 {
    public ListNode reverseBetween(ListNode head, int left, int right) {
        // 定义伪头节点
        ListNode dummyHead = new ListNode(0, head);

        ListNode g = dummyHead;
        ListNode p = dummyHead.next;

        // 将 p 指针指向第 left 个节点（p 当前指向第一个节点，再让 p 向右移动 left-1 次）
        for (int i = 0; i < left - 1; i ++) {
            p = p.next;
            g = g.next;
        }

        // 头插法插入节点：让 p 后面的节点插入到 g 后面（建议配合参考题解理解）
        for (int i = 0; i < right - left; i++) {
            // 删除 p 后面的节点
            ListNode removed = p.next;
            p.next = p.next.next;

            // 头插法插入到 g 的后面
            removed.next = g.next;
            g.next = removed;
        }

        return dummyHead.next;
    }
}

// 参考题解（非常推荐）：https://leetcode-cn.com/problems/reverse-linked-list-ii/solution/java-shuang-zhi-zhen-tou-cha-fa-by-mu-yi-cheng-zho/

