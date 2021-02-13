package Algorithms.leetcode.Ex_2_Add_Two_Numbers;

/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode() {} ListNode(int val) { this.val = val; } ListNode(int val,
 * ListNode next) { this.val = val; this.next = next; } }
 */
class Solution_1 {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode i1 = l1;
        ListNode i2 = l2;
        // 默认以l1为主list
        while (i1 != null && i2 != null) {
            i1.val += i2.val;
            if (i1.val >= 10) {
                this.carryOut(i1);
            }
            if (i1.next == null) {
                i1.next = i2.next;
                break;
            }
            i1 = i1.next;
            i2 = i2.next;
        }
        // 处理i1后的进位
        while (i1 != null) {
            if (i1.val >= 10) {
                this.carryOut(i1);
            }
            i1 = i1.next;
        }
        return l1;
    }

    private void carryOut(ListNode i1) {
        if (i1.next != null) {
            i1.next.val += 1;
        } else {
            i1.next = new ListNode(1);
        }
        i1.val -= 10;
    }
}