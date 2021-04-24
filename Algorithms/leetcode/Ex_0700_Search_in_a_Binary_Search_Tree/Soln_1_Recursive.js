/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} val
 * @return {TreeNode}
 */
var searchBST = function(root, val) {
    if (root == null) {
        return null;
    } else if (root.val > val) {
        // 在左子树中搜索 val
        return searchBST(root.left, val);
    } else if (root.val < val) {
        // 在右子树中搜索 val
        return searchBST(root.right, val);
    } else if (root.val == val) {
        return root;
    }
    return null;
};