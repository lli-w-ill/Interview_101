package Algorithms.leetcode.Ex_0021_Merge_Two_Sorted_Lists;

/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode() {} ListNode(int val) { this.val = val; } ListNode(int val,
 * ListNode next) { this.val = val; this.next = next; } }
 */
class Solution_1 {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null) {
            return l2;
        }
        if (l2 == null) {
            return l1;
        }
        // 默认将l1作为最终的结果链
        ListNode res = new ListNode(-1);
        ListNode r = res;
        ListNode i1 = l1;
        ListNode i2 = l2;
        while (i1 != null && i2 != null) {
            if (i1.val <= i2.val) {
                r.next = i1;
                i1 = i1.next;
            } else {
                r.next = i2;
                i2 = i2.next;
            }
            r = r.next;
        }
        r.next = i1 == null ? i2 : i1;
        return res.next;
    }
}
