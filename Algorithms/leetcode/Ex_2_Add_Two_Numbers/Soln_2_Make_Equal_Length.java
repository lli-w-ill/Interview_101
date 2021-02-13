package Algorithms.leetcode.Ex_2_Add_Two_Numbers;

/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode() {} ListNode(int val) { this.val = val; } ListNode(int val,
 * ListNode next) { this.val = val; this.next = next; } }
 */
class Solution_2 {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        /*
         * 想法： 1. 获取两个链表所对应的长度 2. 在较短的链表末尾补零 3. 对齐相加考虑进位
         */
        // 1. 从第二位开始记长度
        int len1 = 1;
        int len2 = 1;
        ListNode p = l1;
        ListNode q = l2;
        while (p.next != null) {
            len1++;
            p = p.next;
        }
        while (q.next != null) {
            len2++;
            q = q.next;
        }
        // 2. 在较短的链表末尾补零
        if (len1 < len2) {
            // 在p后面补零
            for (int i = 0; i < len2 - len1; i++) {
                p.next = new ListNode(0);
                p = p.next;
            }
        } else {
            // 在q后面补零
            for (int i = 0; i < len1 - len2; i++) {
                q.next = new ListNode(0);
                q = q.next;
            }
        }
        // 3. 对齐相加考虑进位 (默认以l1作为结果链)
        p = l1;
        q = l2;
        int carry = 0;
        while (p.next != null && q.next != null) {
            p.val += q.val + carry;
            carry = 0;
            if (p.val >= 10) {
                p.val -= 10;
                carry = 1;
            }
            p = p.next;
            q = q.next;
        }
        // 最后一位相加
        p.val += q.val + carry;
        if (p.val >= 10) {
            p.val -= 10;
            p.next = new ListNode(1);
        }
        return l1;
    }
}

// 参考：https://leetcode-cn.com/problems/add-two-numbers/solution/liang-shu-xiang-jia-by-gpe3dbjds1/
