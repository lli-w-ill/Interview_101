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
    const nums = [];
    while (head != null) {
        nums.push(head.val);
        head = head.next
    }

    const buildBST = (start, end) => {
        if (start > end) {
            return null;
        }
        const mid = (start + end) >> 1;
        const root = new TreeNode(nums[mid]);
        root.left = buildBST(start, mid - 1);
        root.right = buildBST(mid + 1, end);
        return root;
    }

    // 左右都是闭空间 (与 Ex.108 Soln_2 不同)
    return buildBST(0, nums.length - 1);
};

// 参考题解（强烈推荐）：https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/solution/shou-hua-tu-jie-san-chong-jie-fa-jie-zhu-shu-zu-ku/

