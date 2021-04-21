/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var swapPairs = function(head) {
    if (head == null || head.next == null) {
        return head;
    }

    var next = head.next;   // next 就是每次两两交换后新的“头节点”
    head.next = swapPairs(next.next);
    next.next = head;
    return next;
};

// 参考题解：https://leetcode-cn.com/problems/swap-nodes-in-pairs/solution/hua-jie-suan-fa-24-liang-liang-jiao-huan-lian-biao/

