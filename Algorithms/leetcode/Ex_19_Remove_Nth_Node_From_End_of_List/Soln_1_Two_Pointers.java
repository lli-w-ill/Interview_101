package Algorithms.leetcode.Ex_19_Remove_Nth_Node_From_End_of_List;

/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode() {} ListNode(int val) { this.val = val; } ListNode(int val,
 * ListNode next) { this.val = val; this.next = next; } }
 */
class Solution_1 {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if (head == null) {
            return head;
        }
        ListNode fast = head;
        ListNode slow = head;
        int cnt = 0;
        // 首先先让fast指针先走n步
        while (fast != null && cnt < n) {
            fast = fast.next;
            cnt += 1;
        }
        // 然后slow和fast各自向前走，直到fast.next为空
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next;
        }
        if (fast == null) {
            // 说明要删除的是头节点，直接返回head.next
            return head.next;
        } else if (fast.next == null) {
            // 删除slow.next节点
            slow.next = slow.next.next;
        }
        return head;
    }
}
