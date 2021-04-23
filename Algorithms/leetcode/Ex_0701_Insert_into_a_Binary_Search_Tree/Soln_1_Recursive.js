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
var insertIntoBST = function(root, val) {

    // 找到合适的嫁接节点
    var searchTheProperInsertionNode = (cur, val) => {
        if (cur.left == null && cur.right == null) {
            return cur;
        }

        if (cur.val > val) {
            if (cur.left != null) {
                // 在左子树搜索
                return searchTheProperInsertionNode(cur.left, val);
            } else {
                // 直接返回当前节点，将 val 插在 cur 的左孩子
                return cur;
            }
        } else if (cur.val < val) {
            if (cur.right != null) {
                // 在右子树搜索
                return searchTheProperInsertionNode(cur.right, val);
            } else {
                // 直接返回当前节点，将 val 插在 cur 的右孩子
                return cur;
            }
        }
    }

    if (root == null) {
        root = new TreeNode(val);
        return root;
    }

    let properNode = searchTheProperInsertionNode(root, val);
    if (properNode.val > val) {
        // 新节点作为左孩子
        properNode.left = new TreeNode(val);
    } else if (properNode.val < val) {
        // 新节点作为右孩子
        properNode.right = new TreeNode(val);
    }

    return root;
};

// 进阶：这道题没有要求插入新节点后需要保持当前 BST 的平衡性，即左右子树高度不大于1。记得有一道题是关于「平衡二叉树的插入和删除」

