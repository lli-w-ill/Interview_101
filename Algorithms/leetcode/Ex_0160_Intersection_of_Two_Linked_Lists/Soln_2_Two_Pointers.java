package Algorithms.leetcode.Ex_0160_Intersection_of_Two_Linked_Lists;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
class Solution_2 {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null) {
            return null;
        }
        ListNode pA = headA;
        ListNode pB = headB;
        while (pA != pB) {
            pA = (pA == null) ? headB : pA.next;
            pB = (pB == null) ? headA : pB.next;
        }
        // 如果两条链表有相交点，那么此时 pA 和 pB 都位于相交的起始节点
        // 如果两条链没有相交点，则 pA / pB 会同时指向 headB / headA 链表的末尾节点后的 null，也会退出 while 循环
        return pA;
    }
}

// 参考题解（推荐）：https://leetcode-cn.com/problems/intersection-of-two-linked-lists/solution/tu-jie-xiang-jiao-lian-biao-by-user7208t/

