/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

/**
 * Encodes a tree to a single string.
 *
 * @param {TreeNode} root
 * @return {string}
 */
var serialize = function(root) {
    if (root == null) {
        return 'X';
    }
    const left = serialize(root.left);
    const right = serialize(root.right);
    return root.val + ',' + left + ',' + right; // 顺序：根 左 右
};

/**
 * Decodes your encoded data to tree.
 *
 * @param {string} data
 * @return {TreeNode}
 */
var deserialize = function(data) {
    const list = data.split(',');

    const buildTree = (list) => {
        const rootVal = list.shift();   // 弹出首项
        if (rootVal == 'X') {
            return null;
        }
        const root = new TreeNode(rootVal); // 不是X，创建节点
        root.left = buildTree(list);    // 递归构建左子树
        root.right = buildTree(list);   // 递归构建右子树
        return root;
    }

    return buildTree(list);
};

/**
 * Your functions will be called as such:
 * deserialize(serialize(root));
 */

// 参考题解：https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/solution/shou-hui-tu-jie-gei-chu-dfshe-bfsliang-chong-jie-f/

