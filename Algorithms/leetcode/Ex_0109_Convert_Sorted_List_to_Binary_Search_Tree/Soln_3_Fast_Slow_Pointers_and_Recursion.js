/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {ListNode} head
 * @return {TreeNode}
 */
var sortedListToBST = function(head) {
    if (head == null) {
        return null;
    }
    let slow = head;
    let preSlow = null;     // 记录 slow 的前一个节点
    let fast = head;
    
    // 用快慢指针法找到链表的中点
    while (fast && fast.next) {
        preSlow = slow;
        slow = slow.next;
        fast = fast.next.next;
    }
    // 到这里 slow 指向中点（如果长度是奇数，slow指向恰好是中点；如果长度是偶数，则slow指向中间两个节点的后一个，而preSlow指向中间两个节点的前一个）
    // 断开两个链表
    if (preSlow != null) {
        // 说明当前链表只有一个节点
        preSlow.next = null;
    }

    // 现在有两个链表:
    //      head -> ... -> preSlow -> null
    //      slow -> ... -> fast -> null  或者  slow -> ... -> fast (= null)
    // 然后用 slow 的值做 root，构建左右子树
    const root = new TreeNode(slow.val);
    // 构建左子树
    if (preSlow != null) {
        root.left = sortedListToBST(head);
    } else {
        root.left = null;
    }
    // 构建右子树
    if (slow.next != null) {
        root.right = sortedListToBST(slow.next);
    } else {
        root.right = null;
    }

    // 返回根节点给上一层
    return root;

};

// 参考题解（强烈推荐）：https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/solution/shou-hua-tu-jie-san-chong-jie-fa-jie-zhu-shu-zu-ku/
