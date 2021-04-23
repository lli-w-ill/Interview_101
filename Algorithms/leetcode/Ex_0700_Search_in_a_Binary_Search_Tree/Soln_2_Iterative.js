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
    let stack = [];
    stack.push(root);
    while (stack) {
        const top = stack.pop();
        if (top == null) {
            return null;
        } else if (top.val > val) {
            // 在左子树中搜索
            stack.push(top.left);
        } else if (top.val < val) {
            // 在右子树中搜索
            stack.push(top.right);
        } else if (top.val == val) {
            return top;
        }
    }
    return null;
};
