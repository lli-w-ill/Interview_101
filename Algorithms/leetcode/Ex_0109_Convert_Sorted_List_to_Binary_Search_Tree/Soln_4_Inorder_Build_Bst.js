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
    
    // 计算链表的长度
    let len = 0;
    let h = head;
    while (h != null) {
        len ++;
        h = h.next;
    }

    const buildBST = (start, end) => {
        if (start > end) {
            return null;
        }
        if (start == end) {
            // 记录当前头指针值，并右移头指针
            let headVal = head.val;
            head = head.next;
            return new TreeNode(headVal, null, null);
        }

        const mid = (start + end) >> 1;
        const left = buildBST(start, mid - 1);  // 先递归构建左子树

        const root = new TreeNode(head.val);
        root.left = left;

        // 再递归构建右子树
        head = head.next;   // 右移头指针
        root.right = buildBST(mid + 1, end);

        return root;
    }

    return buildBST(0, len - 1);

};

// 参考题解（强烈推荐）：https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/solution/shou-hua-tu-jie-san-chong-jie-fa-jie-zhu-shu-zu-ku/
