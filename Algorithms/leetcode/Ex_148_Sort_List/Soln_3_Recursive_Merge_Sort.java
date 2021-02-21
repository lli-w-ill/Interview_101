package Algorithms.leetcode.Ex_148_Sort_List;

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
class Solution {
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null) {
            // 链表为空 或 只包含一个元素的链表则直接返回，因为已经是有序的
            return head;
        }
        // cut 环节：分割链表成两个「半链表」
        ListNode slow = head;
        ListNode fast = head.next;  // 让fast先走一步
        // 如果链表长度为偶数，则找到中心两个节点靠左边的那个节点
        // 如果链表长度为奇数，则找到中心节点（中心节点唯一）
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        // 此时slow指向中心节点（长度为偶数），或靠左边的中心节点（长度为奇数）
        // 切断两个「半链表」
        ListNode secondHead = slow.next;
        slow.next = null;
        // 分别对两个「半链表」进行归并排序
        ListNode left = sortList(head);
        ListNode right = sortList(secondHead);

        // merge 环节：利用伪头节点，将两个已经排序的链表合并
        ListNode res = new ListNode(0);
        ListNode it = res;
        while (left != null && right != null) {
            if (left.val <= right.val) {
                it.next = left;
                left = left.next;
            } else {
                it.next = right;
                right = right.next;
            }
            it = it.next;
        }
        it.next = (left != null) ? left : right;
        return res.next;
    }
}

// 参考题解：https://leetcode-cn.com/problems/sort-list/solution/sort-list-gui-bing-pai-xu-lian-biao-by-jyd/
// 时间复杂度：O(nlogn)
// 空间复杂度：O(logn) —— 递归调用空间
