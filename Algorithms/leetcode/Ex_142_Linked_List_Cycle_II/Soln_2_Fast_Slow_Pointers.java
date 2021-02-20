package Algorithms.leetcode.Ex_142_Linked_List_Cycle_II;

/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
class Solution_2 {
    public ListNode detectCycle(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        while (true) {
            if (fast == null || fast.next == null) {
                return null;
            }
            slow = slow.next;
            fast = fast.next.next;
            if (fast == slow) {
                break;
            }
        }
        // 第一次相遇后，此时设 slow 共走了 s 步，则 fast 共走了 f = 2s 步
        // 由于 fast 之所以与 slow 相遇，是因为 fast 套了 slow n圈，所以可得 f = s + nb（b为环内节点总数）
        // 所以联合公式可得 f = 2s = s + nb ==> s = nb, f = 2nb
        // 又因为从 head 要走向第一个环中节点需要走 a + nb 步 (a为从head到第一个环内节点之间的节点数，注：这里包括head，但不算上第一个环内节点)，+nb是因为在环内走一圈是 b 步，走两圈是 2b 步，都会回到第一个环内节点，所以 n = 1, 2, 3, ...
        // 所以只要再让 slow 走 a 步，s 就可以等于 a + b 步，满足 a + nb
        // 置fast回head，并与 slow 同速前进，刚好走完a步相遇，相遇的地方就是第一个环内节点
        fast = head;
        while (fast != slow) {
            slow = slow.next;
            fast = fast.next;
        }
        return fast;
    }
}

// 题解讲解为什么第一次双指针相遇后把fast置为head（强烈推荐）：https://leetcode-cn.com/problems/linked-list-cycle-ii/solution/linked-list-cycle-ii-kuai-man-zhi-zhen-shuang-zhi-/

