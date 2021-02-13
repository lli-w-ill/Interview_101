package Algorithms.leetcode.Ex_2_Add_Two_Numbers;

/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode() {} ListNode(int val) { this.val = val; } ListNode(int val,
 * ListNode next) { this.val = val; this.next = next; } }
 */
class Solution_3 {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode res = new ListNode(-1);
        ListNode r = res;
        ListNode p = l1;
        ListNode q = l2;
        int sum = 0;
        int carry = 0;
        while (p != null || q != null) {
            sum = 0;
            if (p != null) {
                sum += p.val;
                p = p.next;
            }
            if (q != null) {
                sum += q.val;
                q = q.next;
            }
            if (carry > 0) {
                sum += carry;
                carry = 0;
            }
            if (sum >= 10) {
                sum -= 10;
                carry = 1;
            }
            r.next = new ListNode(sum);
            r = r.next;
        }
        if (carry > 0) {
            r.next = new ListNode(carry);
        }
        return res.next;
    }
}

// 参考：https://leetcode-cn.com/problems/add-two-numbers/solution/liang-shu-xiang-jia-by-gpe3dbjds1/
